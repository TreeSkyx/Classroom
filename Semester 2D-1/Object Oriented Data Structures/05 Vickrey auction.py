print("Enter All Bid : ", end='')
bid = input()
all_bid = bid.split()
int_bid = list(map(int, all_bid))
int_bid.sort()
if len(all_bid) < 2:
    print("not enough bidder")
elif int_bid[-1] == int_bid[-2]:
    print("error : have more than one highest bid")
else:
    print("winner bid is", int_bid[-1], "need to pay", int_bid[-2])
