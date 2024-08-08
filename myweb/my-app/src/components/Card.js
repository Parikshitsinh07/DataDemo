import React, { useState } from "react";
//validtion mate import kare lu 6
import PropTypes from "prop-types";

export default function Card(props) {
  const hendalUpClick = () => {
    let newText = text.toUpperCase();
    setText(newText);
    //  console.log(setText);
  };
  const hendleLowClick = () => {
    let newText = text.toLowerCase();
    setText(newText);
    // console.log(setText);
  };
  const hendleOnChange = (event) => {
    setText(event.target.value); //new value add karava
  };
  const hendleClClick = () => {
    // text clear karva mate
    let newText = "";
    setText(newText);
  };
  const [text, setText] = useState("Enter Your text");
  return (
    <>
      <div
        className={`container my-3  bg-${props.mode}-subtle border border-${props.mode}-subtle rounded-3 w-75 `}
        style={{ color: props.mode === "dark" ? "#0a58ca" : "black" }}
      >
        <h1>{props.heading}</h1>
        <div className="mb-3">
          <textarea
            className="form-control"
            value={text}
            onChange={hendleOnChange}
            id="text1"
            rows="3"
            style={{
              backgroundColor: props.mode === "dark" ? "black" : "white",
              color: props.mode === "dark" ? "white" : "black",
            }}
          ></textarea>
          <button className="btn btn-primary mt-2 mx-2" onClick={hendalUpClick}>
            Convart To Uppercase
          </button>
          <button
            className="btn btn-primary mt-2 mx-2"
            onClick={hendleLowClick}
          >
            Convart To Lowercase
          </button>
          <button className="btn btn-primary mt-2 mx-2" onClick={hendleClClick}>
            Clear
          </button>
          <button className="btn btn-primary mt-2 mx-2" onClick={hendleClClick}>
            Clear
          </button>
          <h3>Your text Summary</h3>
          <p>
            {text.split(" ").length}words and {text.length}Charactesrs
          </p>
          <p>{0.008 * text.split(" ").length} minutes Read</p>
          <h3>preview:</h3>
          <p>
            {text.length > 0 ? text : "Enter Your text in text Box for Preview"}
          </p>
        </div>
      </div>
    </>
  );
}
// validtion mate
Card.prototype = {
  heading: PropTypes.string,
};
