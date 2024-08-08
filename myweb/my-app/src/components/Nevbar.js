import React from "react";
import PropTypes from "prop-types";
export default function Nevbar(props) {
  return (
    <nav
      className="navbar navbar-expand-lg bg-body-tertiary"
      data-bs-theme={`${props.mode}`}
    >
      <div className="container-fluid">
        <a className="navbar-brand" href="/">
          {props.title}
        </a>
        <button
          className="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarSupportedContent"
          aria-controls="navbarSupportedContent"
          aria-expanded="true"
          aria-label="Toggle navigation"
        >
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className="collapse navbar-collapse" id="navbarSupportedContent">
          <ul className="navbar-nav me-auto mb-2 mb-lg-0">
            <li className="nav-item">
              <a className="nav-link active" aria-current="page" href="/">
                Home
              </a>
            </li>
            <li className="nav-item">
              <a className="nav-link" href="/">
                SPORTS
              </a>
            </li>
            <li className="nav-item dropdown">
              <a
                className="nav-link dropdown-toggle"
                href="/"
                role="button"
                data-bs-toggle="dropdown"
                aria-expanded="true"
              >
                Services
              </a>
              <ul className="dropdown-menu">
                <li>
                  <a className="dropdown-item" href="/">
                    Form Filing
                  </a>
                </li>
                <li>
                  <a className="dropdown-item" href="/">
                    Web Developing
                  </a>
                </li>
                <li>
                  <hr className="dropdown-divider" />
                </li>
                <li>
                  <a className="dropdown-item" href="/">
                    Other Services
                  </a>
                </li>
              </ul>
            </li>
            <li className="nav-item">
              <a className="nav-link disabled" href="/">
                About Me
              </a>
            </li>
          </ul>
          <form
            className="d-flex"
            role="search"
            style={{ color: props.mode === "dark" ? "white" : "black" }}
          >
            {/* <div className="">
              <label>BackgroundColor</label>
              <input
                className="rounded-pill"
                type="color"
                // style = {color:'black'}
                value={props.myStyle}
                id="flexSwitchCheckChecked"
                onClick={props.toogleStyle}
              />
            </div> */}
            <div className="form-check form-switch">
              <input
                className="form-check-input"
                type="checkbox"
                role="switch"
                id="flexSwitchCheckChecked"
                onClick={props.toogleMode}
              />
              <label
                className="form-check-label"
                htmlFor="flexSwitchCheckChecked"
              >
                Eneble to {props.mode === "light" ? "dark" : "light"} Mode
              </label>
            </div>
          </form>
        </div>
      </div>
    </nav>
  );
}

Nevbar.propTypes = { title: PropTypes.string.isRequired };

Nevbar.defaultProps = {
  // title : "myweb"
};
