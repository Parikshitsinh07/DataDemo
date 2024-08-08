<style>
    .user-panel {
          position: absolute;
            right: 127px;
            top: 73px;                    
        }

        .user-dropdown {
            position: relative;
            display: inline-block;
        }

        .user-icon {
            width: 30px;
            height: 30px;
            border-radius: 50%;
            margin-right: 10px;
        }

        .dropdown-btn {
            background-color: transparent;
            border: none;
            outline: none;
            cursor: pointer;
            font-size: 16px;
        }

        .dropdown-content {
            display: none;
            position: absolute;
            right: 0;
            z-index: 1;
        }

        .dropdown-content a {
            display: block;
            padding: 10px 20px;
            text-decoration: none;
            color: #333;
        }

        .dropdown-content a:hover {
            background-color: #ddd;
        }

        .user-dropdown:hover .dropdown-content {
            display: block;
        }
   
</style>

<?php session_start(); include('header.html')?>
<?php include ('admin.html') ?>
<?php

if(isset($_SESSION['userid'])){
    $user=$_SESSION['userid'];
echo '<div class="user-panel">
    <div class="user-dropdown">
        <img class="user-icon" src="images/usericon.png"> 
        <div class="dropdown-content">
        <a href="#"><button class="dropdown-btn">'.$user.'</button></a>';
        if($user=="Malav" || $user=="Pappu"){
          echo ' <a href="admin.php">Admin</a> ';
        }
       echo '
            <a href="#">User History</a>
            <a href="logout.php">Logout</a>
        </div>
    </div>
</div>';}
if(isset($_POST["submit"])){
// Establish database connection
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "bookstore";

$con =  mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if(!$con){
    echo "Cant connect to database";
    mysqli_error();
   }

// Get form data

$book_img = $_POST['book_img'];
$book_name = $_POST['book_name'];
$book_price = $_POST['book_price'];
$book_category = $_POST['book_category'];
$book_page=$_POST['book_page'];
// Insert data into table
$sql = "INSERT INTO book_information (book_img, book_name, book_price, 	book_categari , book_page)
VALUES ('$book_img', '$book_name', $book_price, '$book_category','$book_page')";
      $result=mysqli_query($con, $sql);
if ($result === TRUE) {
  echo "<script>
    alert('New record created successfully');
    </script>";
} else {
    echo " Somthing Went Wrong !";
}

$con->close();
 }
?>
<?php include('footer.html')?>



