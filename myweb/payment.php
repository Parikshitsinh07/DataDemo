<style>
     .payment-form {
	max-width: 400px;
	margin: 0 auto;
	padding: 20px;
	background-color: #f5f5f5;
	border: 1px solid #ddd;
	border-radius: 5px;
}

h2 {
	text-align: center;
}

form {
	display: flex;
	flex-direction: column;
}

label {
	margin-top: 10px;
	font-weight: bold;
}

input[type="text"] {
	padding: 10px;
	border-radius: 5px;
	border: 1px solid #ccc;
	margin-bottom: 20px;
}

button[type="submit"] {
	background-color: #4CAF50;
	color: white;
	padding: 10px;
	border-radius: 5px;
	border: none;
	cursor: pointer;
	margin-top: 20px;
}

button[type="submit"]:hover {
	background-color: #3e8e41;
}
</style>
<?php
  session_start();
  if(!isset($_SESSION['userid'])) {
    if(isset($_SESSION['cart'])){
    session_destroy();
    }
    echo '<script>alert("Please login to access this page.");</script>';
    header("Location: account.php");
    exit();
  }else{
   echo' <div class="payment-form">
		<h2>Payment Method</h2>
		<form action="process-payment.php" method="post">
			<label for="name">Name on Card</label>
			<input type="text" id="name" name="name" placeholder="John Smith" required>

			<label for="card-number">Card Number</label>
			<input type="text" id="card-number" name="card-number" placeholder="1234 5678 9012 3456" required>

			<label for="expiry-date">Expiry Date</label>
			<input type="text" id="expiry-date" name="expiry-date" placeholder="MM / YY" required>

			<label for="cvv">CVV</label>
			<input type="text" id="cvv" name="cvv" placeholder="123" required>

			<label for="amount">Amount</label>
			<input type="text" id="amount" name="amount" placeholder="$10.00" required>

			<button type="submit">Pay Now</button>
		</form>
	</div>';


  }
?>
