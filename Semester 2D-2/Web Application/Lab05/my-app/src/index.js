import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";

class FoodBox extends React.Component {
  state = {
    voteMsg: 'Min',
  };

  handleCallback = (childData) => {
    if (childData === "1") {
      if (this.state.voteMsg === 9) {
        this.setState({ voteMsg: "Max" });
      } else if (this.state.voteMsg === "Max") {
        alert("Cannot Vote more");
      } else if (this.state.voteMsg === "Min") {
        this.setState({ voteMsg: 0 });
      } else {
        this.setState({ voteMsg: this.state.voteMsg + 1 });
      }
    } else {
      if (this.state.voteMsg === 1) {
        this.setState({ voteMsg: "Min" });
      } else if (this.state.voteMsg === "Min") {
        alert("Cannot unvote");
      } else if (this.state.voteMsg === "Max") {
        this.setState({ voteMsg: 9 });
      } else {
        this.setState({ voteMsg: this.state.voteMsg - 1 });
      }
    }
  };

  render() {
    const { voteMsg } = this.state;
    return (
      <div className="foodBox">
        <div className="grid-container">
          <div className="col1">
            <h3><b>{this.props.foodType}</b></h3>
            <b>{this.props.foodName}</b>
            <br></br>
            <br></br>
            {this.props.msg}
          </div>
          <div className="col2">
            <img src={this.props.img} alt=""></img>
          </div>
          <div className="vote">
            <VoteButton parentCallback={this.handleCallback} /> &nbsp;
            <button name="txt">{voteMsg}</button> &nbsp;
            <UnVoteButton parentCallback={this.handleCallback} />
          </div>
        </div>
      </div>
    );
  }
}

class VoteButton extends React.Component {
  onTrigger = () => {
    this.props.parentCallback("1");
  };
  render() {
    return <button onClick={this.onTrigger}>Click to Vote</button>;
  }
}

class UnVoteButton extends React.Component {
  onTrigger = () => {
    this.props.parentCallback("-1");
  };
  render() {
    return <button onClick={this.onTrigger}>Click to UnVote</button>;
  }
}

class Block extends React.Component {
  render() {
    return (
      <div className="block">
        <h2>โหวตอาหาร</h2>
        <div>
          <FoodBox
            foodType="อาหารคาว"
            foodName="ข้าวผัด"
            msg="Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam nibh nunc, semper at nulla a, venenatis malesuada risus. Aliquam a varius dolor, eget feugiat ante. Mauris ornare enim bibendum, fermentum tellus et, venenatis tortor. Vivamus a vestibulum ex. Etiam tempor purus quis velit luctus pharetra."
            img="https://www.ajinomoto.co.th//storage/photos/shares/our-story/tips/friedrice/62ff47ff5a301.jpg"
          />
          <FoodBox
            foodType="อาหารหวาน"
            foodName="บัวลอย"
            msg="Vivamus iaculis massa et posuere luctus. Aliquam aliquet eu diam at pulvinar. Mauris egestas venenatis diam, venenatis aliquam mi efficitur ut. Morbi feugiat leo non dapibus finibus. Pellentesque scelerisque lacus ac diam imperdiet, sit amet rhoncus nisl viverra. Nulla hendrerit fermentum nisi, sit amet ullamcorper enim volutpat id. Vestibulum lacinia tempor varius. Etiam suscipit ultrices diam."
            img="http://lamphuonline.com/images/00-2022/bua-loi-kaiwan.jpg"
          />
        </div>
      </div>
    );
  }
}
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Block />);
