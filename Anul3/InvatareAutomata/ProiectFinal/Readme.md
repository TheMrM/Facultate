# Android Permissions Analysis and Classification

## Introduction
This project describes the process of analyzing and classifying Android applications based on their permissions. The analyzed dataset contains information about the permissions granted to applications and is used to build machine learning models capable of detecting malware applications.

## Project Objective
The goal of this project is to identify malware applications using machine learning techniques. By analyzing the permissions used by applications, the system determines whether they are benign or malicious, thereby contributing to improved security on the Android platform.

## Development Environment Setup

### 1. Choosing the IDE
For this project, **PyCharm** was chosen due to its advantages:
- Intelligent code completion and static analysis.
- Integration with Jupyter Notebook for interactive result visualization.
- Support for AI/ML libraries such as TensorFlow, PyTorch, and Scikit-Learn.
- Advanced debugging and profiling for optimizing AI models.

### 2. Setting Up the Virtual Environment
To isolate project dependencies, we use a **custom virtual environment**:
1. Create a new project in PyCharm.
2. Select "Custom Environment" to use specific libraries.
3. Install the required libraries via terminal:
   ```sh
   pip install numpy pandas matplotlib seaborn scikit-learn opencv-python
   ```
4. Generate a `requirements.txt` file for dependency management:
   ```sh
   pip freeze | grep -E "numpy|pandas|matplotlib|seaborn|scikit-learn|opencv-python" > requirements.txt
   ```
5. Verify the contents of the file:
   ```sh
   cat requirements.txt
   ```

## Dataset Description
The **NATICUSdroid (Android Permissions)** dataset contains **86 features** representing Android permissions, with a `Result` column indicating whether an application is **benign (0) or malware (1).**

**Key Characteristics:**
- **Total instances:** 29,333
- **Number of features:** 86
- **Data type:** Tabular
- **Task:** Classification

**Dataset Structure:**
- Each row represents an application and its permissions.
- Permissions are indicated by binary values (`1 = present`, `0 = absent`).
- **Source:** [NATICUSdroid Dataset](https://archive.ics.uci.edu/dataset/722/naticusdroid+android+permissions+dataset)

### Data Distribution
A **bar chart** illustrates the class distribution, showing the number of benign (0) and malware (1) instances. The dataset appears to be **balanced**, which is beneficial for classification models as it reduces bias.

## Data Processing and Analysis

### 1. Loading and Exploring the Dataset
- Check the dataset structure:
  ```python
  num_rows, num_cols = df.shape  # Get number of rows and columns
  missing_values = df.isnull().sum().sum()  # Count missing values
  class_distribution = df["Result"].value_counts()  # Check class distribution
  num_duplicates = df.duplicated().sum()  # Count duplicate entries
  ```

### 2. Removing Duplicates
- Remove duplicate rows to improve data quality:
  ```python
  df_cleaned = df.drop_duplicates()
  X = df_cleaned.drop("Result", axis=1)  # Features
  y = df_cleaned["Result"]  # Labels
  ```

### 3. Splitting Data into Training and Testing Sets
- **70% training, 30% testing** using `train_test_split()`:
  ```python
  from sklearn.model_selection import train_test_split
  X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42, stratify=y)
  ```

## Machine Learning Models for Classification

The following four models were tested:

### **1. Logistic Regression**
- **Pros:** Simple, interpretable, computationally efficient.
- **Objective:** Establish a baseline classification model.
- **Accuracy:** **93.77%**
- **Confusion Matrix:**
  ```
  True Positives (Benign) = 1380
  True Negatives (Malware) = 728
  False Positives = 81
  False Negatives = 59
  ```

### **2. Random Forest**
- **Pros:** Handles non-linear relationships, resistant to outliers.
- **Objective:** Improve accuracy compared to Logistic Regression.
- **Accuracy:** **92.83%**
- **Confusion Matrix:**
  ```
  True Positives (Benign) = 1371
  True Negatives (Malware) = 716
  False Positives = 90
  False Negatives = 71
  ```

### **3. AdaBoost**
- **Pros:** Strong generalization ability, reduces overfitting.
- **Objective:** Focus on misclassified instances for better learning.
- **Accuracy:** **91.46%**
- **Confusion Matrix:**
  ```
  True Positives (Benign) = 1345
  True Negatives (Malware) = 711
  False Positives = 116
  False Negatives = 76
  ```

### **4. Support Vector Machine (SVM)**
- **Pros:** Finds an optimal hyperplane for separation.
- **Objective:** Maximize class separation.
- **Accuracy:** **93.46%**
- **Confusion Matrix:**
  ```
  True Positives (Benign) = 1373
  True Negatives (Malware) = 728
  False Positives = 88
  False Negatives = 59
  ```

## Model Evaluation
Each model was trained and tested on the dataset, and accuracy, precision, recall, and F1-score were calculated.

### **10-Fold Cross-Validation Results:**
- **SVM:** **93.47%** (most stable, lowest deviation)
- **Logistic Regression:** **93.39%**
- **Random Forest:** **92.96%**
- **AdaBoost:** **92.19%**

## Conclusions
- **Logistic Regression performed the best** (93.72% accuracy).
- **All models had high accuracy** (between 92.83% and 93.72%).
- **Cross-validation confirmed model stability**, with minor variations.
- **SVM was the most consistent model**, followed closely by Logistic Regression.

### **Possible Improvements:**
- **Hyperparameter tuning** for better model optimization.
- **Larger and more diverse datasets** for improved generalization.
- **Feature selection techniques** to enhance model efficiency.

---
This documentation provides a step-by-step approach to analyzing and classifying Android applications based on permissions, using machine learning models to enhance Android security.

