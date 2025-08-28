#include <stdio.h>
#include <math.h>

int main()
{
    /*
    int a = 2, b = 1;
    printf("%d\n", a / 'b');
    return 0;   
    */

    float price, area, yir, mir; //单价，面积，年利率，月利率
    float interest, loan; //利息，贷款总额
    float ave_repay, down_payment; //月均还款，首期付款
    float total_price, total_repay; //房贷总额，还款总额
    int ratio, time; // 按揭成数，按揭年数

    printf("请输入单价(元/平方米):\t");
    scanf("%f", &price);
    printf("请输入面积(平方米):\t");
    scanf("%f", &area);
    printf("请输入按揭成数:\t");
    scanf("%d", &ratio);
    printf("请输入按揭年数:\t");
    scanf("%d", &time);
    printf("请输入当前基准利率:\t");
    scanf("%f", &yir);

    //计算过程：
    float moun = time * 12.0;
    yir = yir / 10; //年利率
    mir = yir / 120; //月利率
    total_price = area * price; //房款总额
    down_payment = total_price * (1-ratio/10.0); //首付
    loan = total_price * (ratio/10.0); //贷款总额
    ave_repay = loan * (mir * pow((1+mir), moun) / (pow((1+mir), moun) - 1));
    total_repay = (loan * (mir * pow((1+mir), moun) / (pow((1+mir), moun) - 1))) * moun;
    interest = total_repay - loan;

    printf("=======报告结果======\n");
    printf("房款总额: %.2f(元)\n", total_price);
    printf("首期付款: %.2f(元)\n", down_payment);
    printf("贷款总额: %.2f(元)\n", loan);
    printf("还款总额: %.2f(元)\n", total_repay);
    printf("支付利息: %.2f(元)\n", interest);
    printf("月均还款：%.2f(元)\n", ave_repay);
    getchar();
    return 0;
}



