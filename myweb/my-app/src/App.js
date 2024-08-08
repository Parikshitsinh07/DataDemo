// import logo from './logo.svg';
import "./App.css";
import Nevbar from "./components/Nevbar";
import Card from "./components/Card";
import React, { useState } from "react";

function App() {
  const [Mode, setMode] = useState("light");
  const [MyStyle, setMyStyle] = useState("#ffffff");
  const toogleMode = () => {
    if (Mode === "light") {
      setMode("dark");
      document.body.style.backgroundColor = "black";
    } else {
      setMode("light");
      document.body.style.backgroundColor = "white";
    }
  };
  const toogleStyle = () => {};

  return (
    <>
      <Nevbar
        title={"PlaySkillify"}
        mode={Mode}
        toogleMode={toogleMode}
        myStyle={MyStyle}
        toogleStyle={toogleStyle}
      />
      <Card heading="Enter your Text Below" mode={Mode} />
    </>
  );
}
export default App;
