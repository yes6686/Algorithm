class Solution {
    public long solution(long price, long money, long count) {
        
        long totalPrice = 0;
        if(count%2==0){
            totalPrice = (price + (price*count))*(count/2);
        }else{
            totalPrice = (price + (price*count))*(count/2);
            totalPrice+= price*(count/2+1);
        }

        return (totalPrice > money) ? totalPrice-money : 0;
    }
}