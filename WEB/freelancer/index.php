<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Portofoliul meu</title>
	<link rel="stylesheet" type="text/css" href="stil.css">
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Open+Sans:ital,wght@0,300;0,400;0,500;0,600;0,700;0,800;1,300;1,400;1,500;1,600;1,700;1,800&family=Tinos:ital,wght@0,400;0,700;1,400;1,700&display=swap" rel="stylesheet">

    <link href="css/font-awesome.min.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/d3c3cc0b54.js" crossorigin="anonymous"></script>
    <script type="text/javascript" src="script.js"></script>

</head>
<body>
	<div id="wrapper">
		
		<!-- navigare desktop -->
		<header>
			<img src="images/design.png"> <!--site logo -->
			<nav id="desktop">
				<ul>
					<li><a href="#wrapper">Home</a></li>
					<li><a href="#servicii">Servicii</a></li>
					<li><a href="#portofoliu">Portofoliu</a></li>
					<li><a href="#contact">Contact</a></li>
				</ul>
			</nav>
			 <div id="nav-trigger"><a href="#" onclick="toggleMenu()"><i class="fa fa-bars fa-2x" aria-hidden="true" ></i></a></div>
            <nav id="mobile">
            	<a href="#" onclick="toggleMenu()"><i class="fa fa-bars fa-2x" aria-hidden="true" ></i></a>

    			<ul>
    				<li><a href="#wrapper">Home</a></li>
					<li><a href="#servicii">Servicii</a></li>
					<li><a href="#portofoliu">Portofoliu</a></li>
					<li><a href="#contact">Contact</a></li>
    			</ul>
    		</nav>
		</header>

		<!-- hero section -->
		<section id="hero">
			<div id="content-hero">
				<h1>Ciprian Cucu</h1>
				<h2>Programator & designer web.</h2><h2> Full stack dev - HTML5, CSS3, JS, PHP & MySql. Python wrangler, framework slahser, cat enthusiast. </h2>
			</div>
			<div id="image-hero">
				&nbsp;
			</div>
		</section>

<?php
$servername = "localhost";
$username = "root";
$password = "123qaz"; 
$dbname = "Freelance";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
?>

<!-- Dynamic Services Section -->
        <section id="servicii">
            <h1>Servicii oferite</h1>
            <div class="row">
                <?php
                $sql = "SELECT title, image, description FROM services";
                $result = $conn->query($sql);

                if ($result->num_rows > 0) {
                    while($row = $result->fetch_assoc()) {
                        echo '<article><header><img src="' . $row["image"] . '"><h2>' . $row["title"] . '</h2></header><p>' . $row["description"] . '</p></article>';
                    }
                } else {
                    echo "0 servicii găsite";
                }
                ?>
            </div>
        </section>

        <!-- Dynamic Portfolio Section -->
        <h1>Portofoliu</h1>
        <section id="portofoliu">
            <?php
            $sql = "SELECT client_name, title, description FROM projects";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                while($row = $result->fetch_assoc()) {
                    echo '<article><header><h4>' . $row["client_name"] . '</h4><div class="servicii-portofoliu"><img src="images/design.png"></div></header><h2>' . $row["title"] . '</h2><p>' . $row["description"] . '</p></article>';
                }
            } else {
                echo "0 proiecte găsite";
            }
            ?>
        </section>
        <section id="contact">
			<h1>Contactează-mă pentru orice detalii</h1>
			<div class="row">
				<div id="contact-info">
					<h2>Informații de contact:</h2>
					<p><strong>Adresa poștală</strong></p>
					<p>Strada Independenței nr. 10, ap. 23, Alba Iulia, jud. Alba.</p>
					<p><strong>Tel.:</strong> 0723241421</p>
					<p><strong>Email.:</strong> ciprian@cucu.ro</p>
					<p><strong>Social media:</strong></p>
					<div class="social-media">
						<img src="images/design.png">
						<img src="images/design.png">
						<img src="images/design.png">
					</div>
				</div>
				<div id="contact-form" class="form-style-2">
					<h2>Scrie un mesaj aici:</h2>
					<form>
						<label for="field1"><span>Nume <span class="required">*</span></span>
							<input type="text" class="input-field" name="field1" value="" />
						</label>
						<label for="field2"><span>Email <span class="required">*</span></span>
							<input type="text" class="input-field" name="field2" value="" />
						</label>

						<label for="field4"><span>Subiect</span>
							<select name="field4" class="select-field">
								<option value="general">General</option>
								<option value="web">Dezvoltare web</option>
								<option value="design">Design grafic</option>
							</select>
						</label>
						
						<label for="field5">
							<span>Mesaj <span class="required">*</span></span>
							<textarea name="field5" class="textarea-field"></textarea>
						</label>

						<input type="submit" value="Trimite" />
							
					</form>
				</div>
			</div>

		</section>

		<footer>
			<img src="images/design.png"> <!--site logo -->
			<p>© 2021. Design și implementare: Prenume Nume. Toate drepturile rezervate.</p>
		</footer>
	</div>
<?php
$conn->close();
?>

</body>
</html>