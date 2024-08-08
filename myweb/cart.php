<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Cart | Ebookstore</title>
  <link rel="stylesheet" href="style.css" />
  <link rel="preconnect" href="https://fonts.gstatic.com" />
  <link href="https://fonts.googleapis.com/css2?
      family=Poppins:ital,wght@0,200;0,300;0,400;0,500;0,600;1,100;1,200;1,300;1,400;1,500;1,600&display=swap"
    rel="stylesheet" />
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" />
  <style>
    .user-panel {
      position: absolute;
        right: 127px;
        top: 53px;                    
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
    #note1{
      text-align:center;
      font-size:30px;
      
    }
 

</style>
</head>

<body>
  <!------------------ Header ------------------>
  <div class="container">
    <div class="navbar">
      <div class="logo">
        <a href="index.php">
          <img src="images/EbookStore-Logo.png" alt="EbookStore-Logo" />
        </a>
      </div>
      <!----------  Nav Bar ------------------>
      <nav>
        <ul id="MenuItems">
          <li><a href="index.php">Home</a></li>
          <li><a href="ebooks.php">Ebooks</a></li>

          <li><a href="Contact.php">Contact</a></li>
          <li><a href="account.php">Account</a></li>
        </ul>
      </nav>
      <a href="cart.php">
        <img src="images/cart.png" alt="Shoping Cart" width="28px" height="28px"
          style="margin-left: 10px; margin-top: 15px" /></a>
      <img src="images/menu.png" class="menu-icon" onclick="menutoggle()" />
    </div>
  </div>
  <!-- ---------- cart items details------------- -->
  <div class="small-container cart-page">
       <table>
         <tr>
        <th>Ebook</th>
        <th>Quantity</th>
        <th>Subtotal</th>
        <th>order Now</th>

      </tr>
      <!DOCTYPE html>
<html>
<head>
	<title>Payment Method</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<?php 
     session_start(); // start the session
     if(isset($_SESSION['userid'])){
      $user=$_SESSION['userid'];
      echo '<div class="user-panel">
          <div class="user-dropdown">
              <img class="user-icon" src="images/usericon.png"> 
              <div class="dropdown-content">
              <a href="#"><button class="dropdown-btn">'.$user.'</button></a>';
              if($user=="Malav"  || $user=="Pappu"){
                echo ' <a href="admin.php">Admin</a> ';
              }
             echo '
                  <a href="#">User History</a>
                  <a href="logout.php">Logout</a>
              </div>
          </div>
      </div>';
    }
 if(isset($_SESSION['cart'])){
   // output the cart session for testing purposes
  $id=($_SESSION['cart']);
  $quentity =$_POST['items'];
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

   $sql = "INSERT INTO cart_details(`book_id`, `book_quentity`) VALUES ($id,$quentity)";
  
   $result = mysqli_query($con, $sql);
    if($result){
      // echo "your data inserted ";
          }
    $sql2="select * from `cart_details` where  book_id =".$id;
      
    $result2 = mysqli_query($con, $sql2);
    if (mysqli_num_rows($result2) > 0) {
    while($row = mysqli_fetch_array($result2)){
        $product_id = $row['book_id'];
        $select_products="select * from book_information where book_id = '$product_id'";
        $result_prod = mysqli_query($con,$select_products);
      
        while($row_product_price = mysqli_fetch_array($result_prod)){
          // $dis_prize = array($row_product_price['book_img']);
          $price_table = $row_product_price['book_name'];
          $product_title = $row_product_price['book_price'];
          $product_img1 = $row_product_price['book_img'];
          // $product_values = array_sum( $dis_prize );
          // $total += $product_values;
        }
    
    }
    
   echo '<tr>
   <td>
     <div class="cart-info">
       <img src="'.$product_img1.'" alt="Book 16" />
       <div>
         <p>'.$price_table.'</p>
         <small>Price:'.$product_title.'</small> <br />
         <a href="index.php">Remove</a>
       </div>
     </div>
   </td>
   <td><input type="button" value="'.$quentity.'"name="new" /></td>
   <td>'.$product_title*$quentity.'</td>
   <td><a href="payment.php"><button type="submit" class="btn">Buy Now</button></a></td>
 </tr>';
  }
    //   if($result2){
    //   session_destroy();
    //  }
// Close database connection
   mysqli_close($con);
}
else{
  echo "<tr><td colspan='4' id='note1'> Your cart is empty </td></tr>";
   }

?>

    </table>
    <!-- <div class="total-price">
      <table>
        <tr>
          <td>Subtotal</td>
          <td>Rs1500.00</td>
        </tr>
        <tr>
          <td>Tax</td>
          <td>Rs100.00</td>
        </tr>
        <tr>
          <td>Total</td>
          <td>Rs1600.00</td>
          
        </tr>
      </table>
    </div> -->
  </div>
  <!-- ---------------------footer------------------- -->
  <div class="footer">
    <div class="container">
      <div class="row">
        <div class="footer-col-1">
          <h3>Download Our App</h3>
          <p>Download App for Android and ios mobile phone.</p>
          <div class="app-logo">
            <img src="images/Playstore.png" />
            <img src="images/Applestore.png" />
          </div>
        </div>
        <div class="footer-col-2">
          <img src="images/EbookStore-Logo-footer.png" />
          <p>
            Lorem ipsum, dolor sit amet consectetur adipisicing elit.
            Reiciendis, Lorem ipsum dolor sit amet.
          </p>
        </div>
        <div class="footer-col-4">
          <h3>Follow us</h3>
          <ul>
            <li>Facebook</li>
            <li>Youtube</li>
            <li>Instagram</li>
            <li>Twitterr</li>
          </ul>
        </div>
      </div>
      <hr />
      <p class="copyright">Copyright 2020 - EbookStore</p>
    </div>
  </div>
  <!-- ---------Javascript for toggle menu------------- -->
  <script>
    var MenuItems = document.getElementById("MenuItems");
    MenuItems.style.maxHeight = "0px";
    function menutoggle() {
      if (MenuItems.style.maxHeight == "0px") {
        MenuItems.style.maxHeight = "200px";
      } else {
        MenuItems.style.maxHeight = "0px";
      }
    }
    
  </script>
</body>

</html>