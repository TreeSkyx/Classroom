import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";

const FoodBox = (props) => {
  return (
      <div className="foodBox">
        <div className="grid-container">
          <div className="col1">
        <h3>{props.foodType}</h3>
        {props.foodName}
        <br></br>
        <br></br>
        {props.msg}
        </div>
        <div className="col2">
        <img src={props.img} alt=""></img>
        </div>
      </div>
      </div>
  );
};
export default FoodBox;

class Block extends React.Component {
  render() {
    return (
      <div className="block">
        <h2>โหวตอาหาร</h2>
        <div>
          <FoodBox
            foodType="อาหารคาว"
            foodName="ข้าวผัด"
            msg="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam nibh nunc, semper at nulla a, venenatis malesuada risus. Aliquam a varius dolor, eget feugiat ante. Mauris ornare enim bibendum, fermentum tellus et, venenatis tortor. Vivamus a vestibulum ex. Etiam tempor purus quis velit luctus pharetra. Ut finibus mauris at semper blandit. Ut eget lectus pellentesque, consequat mauris at, facilisis neque. Maecenas laoreet luctus purus eget molestie. Praesent dui arcu, vulputate eu elit eget, porta placerat eros. Sed vestibulum vestibulum mauris non vestibulum."
            img="https://www.ajinomoto.co.th//storage/photos/shares/our-story/tips/friedrice/62ff47ff5a301.jpg"
          />
          <FoodBox foodType="อาหารหวาน" foodName="บัวลอย" msg="Vivamus iaculis massa et posuere luctus. Aliquam aliquet eu diam at pulvinar. Mauris egestas venenatis diam, venenatis aliquam mi efficitur ut. Morbi feugiat leo non dapibus finibus. Pellentesque scelerisque lacus ac diam imperdiet, sit amet rhoncus nisl viverra. Nulla hendrerit fermentum nisi, sit amet ullamcorper enim volutpat id. Vestibulum lacinia tempor varius. Etiam suscipit ultrices diam. Nam pulvinar tempus nulla nec imperdiet. Aliquam erat volutpat. Maecenas faucibus ultricies mi, euismod blandit augue accumsan eu. Donec tellus magna, ultricies at lacus ut, dictum ornare justo. Mauris ligula nisi, ullamcorper quis auctor sed, bibendum eu justo." 
          img="https://img.kapook.com/u/2022/wanwanat/1079595941.jpg" />
        </div>
      </div>
    );
  }
}
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Block />);
