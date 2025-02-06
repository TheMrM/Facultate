import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import os
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.svm import SVC

sns.set_style("whitegrid")

# 1. Încărcarea setului de date
df = pd.read_csv("data.csv")
print("Analiza inițială a datasetului:")
print(f"Număr total de rânduri: {df.shape[0]}, Număr total de coloane: {df.shape[1]}")
print(f"Număr de valori lipsă în dataset: {df.isnull().sum().sum()}")
if "Result" in df.columns:
    print(f"Distribuția claselor (Result): {df['Result'].value_counts()}")
else:
    print("Avertizare: Coloana 'Result' nu există în dataset!")
print(f"Număr de duplicate în dataset: {df.duplicated().sum()}")

# 2. Histogramă pentru distribuția claselor (Result)

if "Result" in df.columns:
    plt.figure(figsize=(6, 4))
    sns.countplot(x=df["Result"], hue=df["Result"], palette="coolwarm", legend=False)
    plt.xlabel("Clasă (0 = Benign, 1 = Malware)")
    plt.ylabel("Număr de instanțe")
    plt.title("Distribuția claselor în dataset")
    plt.tight_layout()
    plt.show()
else:
    print("Avertizare: Coloana 'Result' nu există în dataset!")


# 3. Histogramă pentru numărul de valori lipsă per coloană

missing_values = df.isnull().sum()
missing_values = missing_values[missing_values > 0]  # Selectăm doar coloanele cu valori lipsă

if not missing_values.empty:
    plt.figure(figsize=(8, 4))
    missing_values.plot(kind="bar", color="red")
    plt.xlabel("Coloane")
    plt.ylabel("Număr de valori lipsă")
    plt.title("Număr de valori lipsă per coloană")
    plt.xticks(rotation=90)
    plt.show()

# 4. Histogramă pentru identificarea duplicatelor

duplicates_count = df.duplicated().sum()
plt.figure(figsize=(5, 3))
sns.barplot(x=["Unice", "Duplicate"], y=[df.shape[0] - duplicates_count, duplicates_count], hue=["Unice", "Duplicate"], palette="pastel", legend=False)
plt.ylabel("Număr de instanțe")
plt.title("Distribuția duplicatelor în dataset")
plt.show()

# 5. Curățarea datasetului
if df.duplicated().sum() > 0:
    print("\nExemple de date duplicate:\n")
    print(df[df.duplicated()].head(10))  # Afișează primele 10 duplicate

df_cleaned = df.drop_duplicates()

if "Result" in df_cleaned.columns:
    X = df_cleaned.drop(columns=["Result"])
    y = df_cleaned["Result"]
else:
    raise KeyError("Coloana 'Result' nu există în dataset! Verifică setul de date.")

# 6. Împărțirea setului în 70% train / 30% test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42, stratify=y)

# 7. Antrenarea și testarea modelelor de clasificare
models = {
    "Logistic Regression": LogisticRegression(max_iter=1000, random_state=42),
    "Random Forest": RandomForestClassifier(n_estimators=100, random_state=42),
    "AdaBoost": AdaBoostClassifier(n_estimators=50, random_state=42),
    "SVM": SVC(kernel="linear", random_state=42)
}

results = {}
conf_matrices = {}

for name, model in models.items():
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    results[name] = {
        "Accuracy": accuracy,
        "Report": classification_report(y_test, y_pred, output_dict=True)
    }
    conf_matrices[name] = confusion_matrix(y_test, y_pred)
    # Afiseaza matricea de confuzie si rezultatele
    print(f"\n### {name} ###")
    print("Accuracy:", accuracy)
    print("Classification Report:\n", classification_report(y_test, y_pred))
    cm = confusion_matrix(y_test, y_pred)
    plt.figure(figsize=(6, 4))
    sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["Benign", "Malware"], yticklabels=["Benign", "Malware"])
    plt.xlabel("Predicted")
    plt.ylabel("Actual")
    plt.title(f"Confusion Matrix - {name}")
    plt.show()

# 8. Validare încrucișată cu 10-fold
cv_results = {}
for name, model in models.items():
    scores = cross_val_score(model, X, y, cv=10, scoring="accuracy")
    cv_results[name] = {
        "Mean Accuracy": scores.mean(),
        "Std Dev": scores.std()
    }
    print(f"Cross Validation Results for {name}: Mean Accuracy = {scores.mean():.3f}, Std Dev = {scores.std():.3f}")

# 9. Creare DataFrame-uri pentru fiecare categorie de date
results_df = pd.DataFrame(results).T
cv_results_df = pd.DataFrame(cv_results).T

# 10. Crearea unui fișier Excel cu mai multe sheet-uri

file_name = 'project_results.xlsx'
if os.path.exists(file_name):
    os.remove(file_name)

with pd.ExcelWriter('project_results.xlsx') as writer:
    results_df.to_excel(writer, sheet_name='Model Results')
    cv_results_df.to_excel(writer, sheet_name='CV Results')
    for model_name, matrix in conf_matrices.items():
        sheet_name = f'{model_name[:24]} Conf Mat'
        pd.DataFrame(matrix, index=["Actual Benign", "Actual Malware"], columns=["Predicted Benign", "Predicted Malware"]).to_excel(writer, sheet_name=sheet_name)

print("Fișierul Excel cu toate rezultatele a fost creat cu succes!")
