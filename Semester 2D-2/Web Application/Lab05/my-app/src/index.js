import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";

const FoodBox = props => {
  return <div className="foodBox">
    {
      props.msg
    }
  </div>
};
export default FoodBox

class Block extends React.Component {
  render() {
    return (
      <div className="block">
        <h2>โหวตอาหาร</h2>
        <div>
          <FoodBox msg="Hi"></FoodBox>
          <FoodBox msg="Hello"></FoodBox>
      </div>
      </div>
    );
  }
}
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Block />);
