#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<windows.h>
#include<time.h>
#include<conio.h>
void choose();
//建立关于店铺的结构体 
typedef struct shop
{
	char name[20];
	char phone[20];
	char address[30];
	char password[20];
	struct shop *next;
}shop,*link_shop;
//建立关于订单的结构体 
typedef struct food
{
	char name[20];
	int type;
	int amount;
	int price;
	int total;
	char shop[20];
	char yonghu[20];
	char leibie[20]; 
	struct food *next; 
}food,*link_food;
//建立关于用户的结构体
typedef struct user
{
	char name[20];
	char delivery[39];
	char password[15];
	char number[15];
	int score;
	struct user *next;
}user,*link_user;
typedef struct money
{
	char person[20];
	char card[25];
	char mima[20];
	struct money *next;
}money,*link_money;
char yh[20];//用户设置全局变量 
char dp[20];//店铺设置全局变量  
time_t start,end;
//函数声明
void foodwrite(link_food LF);
void shopwrite1(link_shop LS);
void dingdanwrite(link_food LF);
void user_moneywrite(link_user LM);
void welcome()
{
	int i=0;
	char a[52]="▲▼WELCOME TO RESTAURANT MANAGEMENT SYSTEM▲▼";
	//system("color 0a");
	printf("\n\n\n\n\t\t");
	while(a[i])
	{
		printf("%c",a[i]);
		Sleep(50);
		i++;
	}
	printf("\n\n\n\n\t\t");
}
void Exit()
{
	int i=0;
	system("cls");
	char a[20]="LOVE you,byebye^_^";
	system("color 03");
	printf("\n\n\n\t\t\t");
	while(a[i])
	{
		printf("%c",a[i]);
		Sleep(100);
		i++;
	}
}
void ME()
{
	system("color 0b");
	printf("\n\n\n\t\t☆★  W E L C O M E  ☆★\n\n\t这里是外卖管理系统，请选择接下来的操作：");
	printf("\n\n\t\t\t1.登陆");
	printf("\t\t\t2.注册\t\t\t0.退出\n"); 
}
//主菜单（登陆或者注册）	
void MENU()
{
	printf("\n\n\n\n\t\t\t\t\t================================\n");
	printf("\t\t\t\t\t     外  卖  管  理  系  统     \n");
	printf("\t\t\t\t\t          1.管理员登陆          \n");
	printf("\t\t\t\t\t          2.用户登录            \n");
	printf("\t\t\t\t\t          3.店家登陆            \n");
	printf("\t\t\t\t\t          0.返回上一级          \n");
	printf("\t\t\t\t\t================================\n");
}
//管理员选项 
void MENU1()
{
	system("color 0f");
	printf("                                                                         温馨小提示：按5可以清屏哦^-^\n");
	printf("\n\n\t\t\t\t\t1.查看店铺信息▲\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t2.店铺信息修改▼\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t3.处理申请店铺▲\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t4.修改本人信息▼\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t0.返回上一级  ▲\n");
}
//用户选项 
void MENU2()
{
	system("color 0f");
	printf("\n\n\t\t\t\t 1.用户相关 ▲\t\t\t 5.购买菜品 ▼\n"); 
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 2.查看订单 ▲\t\t\t 6.订单排序▼\n");
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 3.查看菜品 ▲\t\t\t 0.返回上级 ▼\n");
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 4.修改订单 ▲\n");
}
//店主选项 
void MENU3()
{
	system("color 0f");
	printf("\n\n\n\t\t\t ________ Shop Version _______\n");
	printf("\t\t\t|                             |\n");
	printf("\t\t\t|          1.添加菜品         |\n");
	printf("\t\t\t|          2.修改菜品         |\n");
	printf("\t\t\t|          3.删除菜品         |\n");
	printf("\t\t\t|          4.查看菜品         |\n");
	printf("\t\t\t|          5.查看业绩         |\n");
	printf("\t\t\t|          0.返回上一级       |\n");
	printf("\t\t\t|_____________________________|\n");
}
//建立关于单链表
void *creatf()
{
	int i=0,n;
	link_food LF;
	food *s,*r;
	char a[10];
	//srand((unsigned)time(NULL));//产生随机数的种子 
	LF=(food *)malloc(sizeof(food));
	LF->next=NULL;
	r=LF;
	while(1)
	{
		printf("请输入菜的名称：");
		scanf("%s",a);
		if(strcmp(a,"0")!=0)
		{
			s=(food *)malloc(sizeof(food));
			printf("请输入菜的单价：");
			scanf("%d",&s->price);
			printf("请输入菜的类别");
			scanf("%s",s->leibie); 
			strcpy(s->name,a);
			s->total=(s->amount)*(s->price);
			r->next=s;
			s->next=NULL;
			r=s;
		} 
		else
			break;
	}
	foodwrite(LF); 
} 
shop *creats()
{
	char a[30],b[20],c[15],d[20];
	link_shop LS;
	shop *s,*r;
	LS=r=(shop *)malloc(sizeof(shop));
	LS->next=NULL;
	r=LS;
	while(1)
	{
		printf("请输入店铺信息:\n");
		printf("\t\t●    店铺名称：");
		scanf("%s",a);
		printf("\n\t\t●    店铺电话：");
		scanf("%s",b);
		if(strcmp(b,"0")!=0)
		{
			printf("\n\t\t●    店铺地址：");  
			scanf("%s",c);
			printf("\n\t\t●    店铺密码：");  
			scanf("%s",d);
			s=(shop *)malloc(sizeof(shop));
			strcpy(s->name,a);
			strcpy(s->phone,b);
			strcpy(s->address,c);
			strcpy(s->password,d);
			r->next=s;
			s->next=NULL;
			r=s;
		}
		else
			break;
	}
	return LS; 
}
void Outputshop(link_shop Ls)
{
	int n=0;
	shop *p,*u;
	p=Ls->next;
	system("cls");
	printf("入驻的商家如下：\n");
	printf("\t\t\t\t-------------------------------------------\n");
	printf("\t\t\t\t店铺名称\t店铺电话\t店铺地址\n");
	printf("\t\t\t\t-------------------------------------------\n");
	while(p)
	{
		printf("\t\t\t\t%8s\t%8s\t%7s\n",p->name,p->phone,p->address);
		printf("\t\t\t\t-------------------------------------------\n");
		p=p->next;
	}
	for(u =Ls->next; u != NULL;u = u->next)  
        n++;
    printf("\t\t\t\t合计\t\t\t\t%d个\n",n);
    printf("\t\t\t\t-------------------------------------------\n");
}
void Outputfood(link_food LF)
{
	food *s;
	s=LF->next;
	int sum=0;
	printf("订单如下：\n");
	printf("\t----------------------------------------------------------------------------------------------------\n");
	printf("\t菜名\t\t数量/份\t\t单价/元\t\t总价/元\t\t店铺\t\t订单号\t\t用户名\n"); 
	printf("\t----------------------------------------------------------------------------------------------------\n");
	for(s=LF->next;s!=NULL;s=s->next)
	{
		if(strcmp(s->yonghu,yh)==0)
		{
			printf("\t%-8s\t%-8d\t%-8d\t%-8d\t%-10s\t%-10d\t%s\n",s->name,s->amount,s->price,s->total,s->shop,s->type,s->yonghu);
			printf("\t----------------------------------------------------------------------------------------------------\n");
			sum=sum+s->total;
		}
	}
	printf("\t累计输出/元\t\t\t\t\t\t\t%d\n",sum);
	printf("\t----------------------------------------------------------------------------------------------------\n");
	if(sum==0)
	{  
		printf("○   您还没有订单呢，快去购买吧  φ(>ω<*) ");
		printf("\n\t\t\t\t\t->");
		Sleep(1000);
		printf("->");
		Sleep(1000);
		printf("->");
		Sleep(1000);
		system("cls");
		MENU2();
		return;
	}
}
void outputfood(link_food LF)
{
	food *p;
	p=LF->next;
	printf("\n\t\t\t                 菜       谱                        "); 
	printf("\n\t\t\t--------------------------------------------------\n");
	printf("\t\t\t菜名        菜价         店铺           菜系\n"); 
	printf("\t\t\t---------------------------------------------------\n");
	while(p)
	{
		printf("\t\t\t%-13s%-12d%-14s%s\n",p->name,p->price,p->shop,p->leibie);
		printf("\t\t\t---------------------------------------------------\n");
		p=p->next;
	}
}
//充值
user* addmoney(user *u)
{
	int n;
	char y;
	char a[20];
	FILE *fp;
	link_money LY;
	money *p,*r;
	printf("您账户里的余额为：%d",u->score);
	printf("是否充值？Y/else");
	fflush(stdin);//清除缓存 
	y=getchar();
	if(y=='Y')
	{
		fp=fopen("yue.txt","rt");
		LY=r=(money *)malloc(sizeof(money));
		LY->next=NULL;
		while(!feof(fp))
		{
			p=(money *)malloc(sizeof(money));
			fscanf(fp,"%s %s %s\n",p->person,p->card,p->mima);
			p->next=NULL;
			r->next=p;
			r=p; 
		}		
		fclose(fp);
		p=LY->next;
		while(1)
		{
			if(strcmp(yh,p->person)==0)
			{
				break;
			}
			else
				p=p->next; 
		}
		printf("充值的钱数？");
		scanf("%d",&n);
		printf("请输入支付密码：");
		scanf("%s",a);
		if(strcmp(p->mima,a)==0)
		{
			u->score=(u->score+n); 
			printf("已充值");
		} 
		else
			printf("\t\t×   密码错误，充值失败");
	}
	else
		printf("已放弃充值");
	return u; 
}					
//按工号排序
void name_sort(link_shop LS)  
{  
    int i,j,n;  
    n = 0;  //记录店铺总数；
    shop *u,*q,*p;
    for(u =LS->next; u != NULL;u = u->next)  
        n++;  
//采用冒泡法对各个节点按姓名升序
    for(i=1;i<=n;i++)  
    {  
        u =LS;  
        for(j=0;j<n-i;j++)  
        {  
            p = u->next;  
            q = p->next;  
            if(strcmp(p->name,q->name) > 0 || strcmp(p->name,q->name) == 0)  
            {  
                u->next = q;  
                p->next = q->next;  
                q->next = p;  
            }  
            u = u->next;  
        }  
    } 
	printf("\t排序后店铺信息\n");
	Outputshop(LS);
	return;
}
void address_sort(link_shop LS)  
{  
    int i,j,n;  
    n = 0;  //记录店铺总数；
    shop *u,*q,*p;
    for(u =LS->next; u != NULL;u = u->next)  
        n++;  
//采用冒泡法对各个节点按地址升序
    for(i=1;i<=n;i++)  
    {  
        u =LS;  
        for(j=0;j<n-i;j++)  
        {  
            p = u->next;  
            q = p->next;
            if(strcmp(p->address,q->address) > 0 || strcmp(p->address,q->address) == 0)  
            {  
                u->next = q;  
                p->next = q->next;  
                q->next = p;  
            }  
            u = u->next;  
        }  
    } 
	printf("\t\t\t\t地址排序后店铺信息\n");
	Outputshop(LS);
	return;
}
void dingdan_name_sort(link_food LF)  //按订单食物名称排序 
{  
    int i,j,n;  
    n = 0;  //记录店铺总数；
    food *u,*q,*p;
    for(u =LF->next; u != NULL;u = u->next)  
        n++;  
//采用冒泡法对各个节点按姓名升序
    for(i=1;i<=n;i++)  
    {  
        u =LF;  
        for(j=0;j<n-i;j++)  
        {  
            p = u->next;  
            q = p->next;  
            if(strcmp(p->name,q->name) > 0 || strcmp(p->name,q->name) == 0)  
            {  
                u->next = q;  
                p->next = q->next;  
                q->next = p;  
            }  
            u = u->next;  
        }  
    } 
	Outputfood(LF);
	return;
}
void dingdan_total_sort(link_food LF)  //按订单总价从高到低排序 
{  
    int i,j,n;  
    n = 0;  //记录店铺总数；
    food *u,*q,*p;
    for(u =LF->next; u != NULL;u = u->next)  
        n++;  
//采用冒泡法对各个节点按姓名升序
    for(i=1;i<=n;i++)  
    {  
        u =LF;  
        for(j=0;j<n-i;j++)  
        {  
            p = u->next;  
            q = p->next;  
            if(p->total>q->total)  
            {  
                u->next = q;  
                p->next = q->next;  
                q->next = p;  
            }  
            u = u->next;  
        }  
    } 
	Outputfood(LF);
	return;
}
void dingdandelete(link_food Lf)
{
	food *p,*n;
	p=Lf;
	n=p->next;
	int m;
	char a;
	printf("请输入你所想删除的订单序号：");
	scanf("%d",&m);
	while(n)
	{
		if(m==n->type)
		{
			if(strcmp(n->shop,dp)==0)
			{
				p->next=n->next;
				//foodwrite(Lf);
				dingdanwrite(Lf);
				break; 
			}
			else
				printf("不好意思，您没有权限删除\n");
			break;
		}
		else
		{
			p=p->next;
			n=n->next;
		}
	}
}
food *dingdanread()
{
	FILE *fp;
	link_food LF,r,s;
	fp=fopen("dingdan.txt","rt");
	if(fp==NULL)
	{ 
		printf("查看订单失败");
		return 0;
	}
	LF=r=(food *)malloc(sizeof(food));
	r->next=NULL;
	while(!feof(fp))
	{
		s=(food *)malloc(sizeof(food));	
		fscanf(fp,"%s %d %d %d %s %d %s\n",s->name,&s->amount,&s->price,&s->total,s->shop,&s->type,s->yonghu);
		r->next=s;
		s->next=NULL;
		r=s;
	}
	return LF;
}
void scorefind(link_food LF)
{
	int sum=0;
	food *p;
	p=LF->next;
	system("cls"); 
	printf("\n\n\n\t\t\t产生的订单如下:\n");
	printf("      ----------------------------------------------------------------------------------------------------\n");
	printf("      菜品名称 \t菜品数量\t菜品单价\t菜品总价\t店铺名称\t订单号 \t\t用户名\n");
	printf("      ----------------------------------------------------------------------------------------------------\n");
	while(p)
	{
		if(strcmp(p->shop,dp)==0)
		{
		printf("    %7s%14d%15d%16d%16s%15d%18s\n",p->name,p->amount,p->price,p->total,p->shop,p->type,p->yonghu);
		printf("      ----------------------------------------------------------------------------------------------------\n");
		sum=sum+p->total;
		}
		p=p->next;
	}
	printf("      合计/元：\t\t\t\t\t\t\t累计收入%d\n",sum);
	printf("      ----------------------------------------------------------------------------------------------------\n");
	if(sum==0)
		printf("\t\t●   您店里的菜还没有人购买哦，应该反思啦\n");
}
food * foodread()//读取 
{
	link_food LF;
	food *s,*r;
	LF=r=(food *)malloc(sizeof(food));
	LF->next=NULL;
	FILE *fp;
	fp=fopen("food.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开此文件");
		exit(1); 
	}
	while(!feof(fp))//判断文件指针是否处于文件结束位置，若是，返回1，非，返回0 
	{
		s=(food *)malloc(sizeof(food));	
		fscanf(fp,"%s %d %s %s\n",s->name,&s->price,s->shop,s->leibie);
		r->next=s;
		s->next=NULL;
		r=s;
	}
	fclose(fp);
	return LF;	
 }
money * moneyread()//读取 
{
	link_money LM;
	money *s,*r;
	LM=r=(money *)malloc(sizeof(money));
	LM->next=NULL;
	FILE *fp;
	fp=fopen("yue.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开此文件");
		exit(1); 
	}
	while(!feof(fp))//判断文件指针是否处于文件结束位置，若是，返回1，非，返回0 
	{
		s=(money *)malloc(sizeof(money));	
		fscanf(fp,"%s %s %s\n",s->person,s->card,s->mima);
		r->next=s;
		s->next=NULL;
		r=s;
	}
	fclose(fp);
	return LM;	
 }
shop * shopread()
{
	link_shop LS;
	shop *s,*r;
	LS=r=(shop *)malloc(sizeof(shop));
	r->next=NULL;
	FILE *fp;
	fp=fopen("shop.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开此文件");
		exit(1); 
	}
	while(!feof(fp))//判断文件指针是否处于文件结束位置，若是，返回1，非，返回0 
	{
		s=(shop *)malloc(sizeof(shop));
		s->next=NULL;
		fscanf(fp,"%s %s %s %s\n",s->name,s->phone,s->address,s->password);
		r->next=s;
		r=s;
	}
	fclose(fp);
	return LS;	
 }
user * userread()
{
	link_user LU;
	user *s,*r;
	LU=r=(user *)malloc(sizeof(user));
	r->next=NULL;
	FILE *fp;
	fp=fopen("users.txt","rt");
	if(fp==NULL)
	{
		printf("不能打开此文件");
		exit(1); 
	}
	while(!feof(fp))//判断文件指针是否处于文件结束位置，若是，返回1，非，返回0 
	{
		s=(user *)malloc(sizeof(user));
		s->next=NULL;
		fscanf(fp,"%s %s %s %s %d\n",s->name,s->delivery,s->password,s->number,&s->score);
		r->next=s;
		r=s;
	}
	fclose(fp);
	return LU;	
 } 
void deleteshop(link_shop LS)
{
	int i=0;
	shop *p,*q;
	p=LS;
	q=p->next;
	char m[20];
	char a;
	printf("请输入你所想删除的店铺名称或者电话：");
	scanf("%s",m);
	while(q)
	{
		if(strcmp(m,q->name)==0||strcmp(m,q->phone)==0)
		{
			i++;
			p->next=q->next;
			shopwrite1(LS);
			return;
		}
		else
		{
			p=p->next;
			q=q->next;
		}
	}
	if(i==0)
	{
		printf("没有此店铺，无法删除\n");
		return;
	}
}
void deletedingdan(link_food Lf)
{
	food *p,*n;
	p=Lf;
	n=p->next;
	int m,i=0;
	char a;
	printf("请输入你所想删除的订单号：");
	scanf("%d",&m);
	while(n)
	{
		if(n->type==m)
		{
			if(strcmp(n->yonghu,yh)==0)
			{
				p->next=n->next;
				i++;
				foodwrite(Lf);
			}
			else
				printf("不好意思，您没有权限删除\n");
			break;
		}
		else
		{
			p=p->next;
			n=n->next;  
		}
	}
	if(i==0)
	{
		printf("\t没有此订单，无法删除\n");
		return;
	}
}
void purchase()
{
	link_food Lf;
	money *LM,*mo;
	user *lu,*us;
	FILE *fp;
	char a[20],b[20],mi[20];
	char y;
	int i=0;
	printf("\t\t◇您想吃啥呢？");
	scanf("%s",a);
	Lf=foodread();
	food *p;
	p=Lf->next;
	srand((unsigned)time(NULL));//订单号的种子 
	while(p!=NULL)
	{
		if(strcmp(p->name,a)==0||strcmp(p->leibie,a)==0)
		{
		//	printf("%s\t%d\t%s\n",p->name,p->price,p->shop);
			i++;
		}	
		p=p->next;	
	}
	if(i==0)
	{
		printf("\t\t\t×不好意思，还没有此菜呢\n");
		system("pause");
		system("cls");
		MENU2();
		return; 
	}
	else
	{
		p=Lf->next;
		printf("\n\t\t\t--------------------------------------------------\n");
		printf("\t\t\t菜名        菜价         店铺           菜系\n"); 
		printf("\t\t\t---------------------------------------------------\n");
		while(p)
		{
			if(strcmp(p->leibie,a)==0||strcmp(p->name,a)==0)
			{
				printf("\t\t\t%-13s%-12d%-14s%s\n",p->name,p->price,p->shop,p->leibie);
				printf("\t\t\t---------------------------------------------------\n");
			}
			
			p=p->next;
		}
	}
	printf("\t\t◇请输入要购买的店铺：");
	scanf("%s",b);
	lu=userread();
	us=lu->next;
	while(us)
	{
		if(strcmp(yh,us->name)==0)
			break;
		else
			us=us->next;
	}//找出要购买的用户信息 
	LM=moneyread();
	mo=LM->next;
	i=0;
	while(mo)
	{
		if(strcmp(yh,mo->person)==0)
		{
			i++;
			break;
		}
		
		else
			mo=mo->next;
	}//找出用户的银行卡信息 
	if(i==0)
	{
		printf("\t\t×   您还没有绑定银行卡哦，不能购买的");
		return; 
	}
	p=Lf->next;
	i=0;
	while(p)
	{
		if(strcmp(p->name,a)==0||strcmp(p->leibie,a)==0)
		{
			if(strcmp(p->shop,b)==0)
			{
				printf("\t\t◇请输入要购买的数量");
				scanf("%d",&p->amount);
				if(p->amount!=0)
				{
					i++;
					p->total=(p->amount)*(p->price);
					p->type=rand()%900+100;
					if((us->score)<p->total)
					{
						printf("\t\t×   您的账号余额不足，请先充值\n");
						system("pause");
						system("cls");
						MENU2();
						return;
					}
					printf("\t\t●确认购买？Y/else");
					fflush(stdin);
					y=getchar();
					if(y=='Y')
					{
						printf("请输入支付密码:");
						scanf("%s",mi);
						if(strcmp(mi,mo->mima)==0)
						{
							fp=fopen("dingdan.txt","at");
							if(fp==NULL)
								printf("\t\t\t\t×购买失败\n");//因文件无法打开而失败
							else
							{
								fprintf(fp,"%s %d %d %d %s %d %s\n",p->name,p->amount,p->price,p->total,p->shop,p->type,yh);
								fclose(fp);
								us->score=(us->score)-(p->total);
								user_moneywrite(lu);
								printf("\t\t\t\t√购买成功，请耐心等待配送\n");
								start = time(NULL);//计时 
								system("pause");
								system("cls");
								MENU2();
								return;
							}		
						}
						else
						{
							printf("\t\t×   密码错误，购买失败");
							system("pause");
							system("cls");
							MENU2();
							return;  
						}		 
					} 
					else
					{
						printf("\t\t\t×已放弃购买");
						system("pause");
						system("cls");
						MENU2();
						return; 
					}
				}
				else
				{
					printf("\t\t\t×请输入正确的数量");
					system("pause");
					system("cls");
					MENU2();
					return; 
				}
			}
		}
		p=p->next;
	}
	if(i==0)
	{
		printf("\t\t×请输入表中的店铺名称哦\n");
		system("pause");
		system("cls");
		MENU2(); 
	}
}
void foodwrite(link_food LF)//保存 
 {
 	FILE *fp;
	food *p;
	char a;
	printf("确认保存？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("food.txt","at");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %s %s\n",p->name,p->price,dp,p->leibie);
		printf("修改成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃修改");
 }
 void foodwrite1(link_food LF)
 {
 	FILE *fp;
	food *p;
	char a;
	printf("确认保存？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("food.txt","wt");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %s %s\n",p->name,p->price,p->shop,p->leibie);
		printf("修改成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃修改");
 }
// void foodwrite2(link_food LF)
// {
// 	FILE *fp;
//	food *p;
//	char a;
//	printf("确认保存？(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
//		fp=fopen("food.txt","wt");
//		if(fp==NULL)
//			printf("错误！无法打开");
//		for(p=LF->next;p!=NULL;p=p->next)
//			fprintf(fp,"%s %d %s %s\n",p->name,p->price,p->shop,p->leibie);
//		printf("修改成功\n");
//		fclose(fp);
//		return;
//	}
//	else
//		printf("已放弃修改");
// }
 void dingdanwrite(link_food LF)
 {
 	FILE *fp;
	food *p;
	char a;
	printf("确认保存？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("dingdan.txt","wt");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %d %d %s %d %s\n",p->name,p->amount,p->price,p->total,p->shop,p->type,p->yonghu);
		printf("修改成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃修改"); 
 }
void shopwrite1(link_shop LS)
 {
 	FILE *fp;
	shop *p;
	char a;
	printf("确认保存？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("shop.txt","wt");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LS->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s\n",p->name,p->phone,p->address,p->password);
		printf("保存成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃");
 }
 void shopwrite2(link_shop LS)
 {
 	FILE *fp;
	shop *p;
	char a;
	printf("是否将信息保存至文件里？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("shop.txt","at");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LS->next;p!=NULL;p=p->next)
		fprintf(fp,"%s %s %s\n",p->name,p->phone,p->address);
		printf("修改成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃修改");
	 
 }
 void userwrite(link_user LU)
 {
 	FILE *fp;
	user *p;
	char a;
//	printf("请确认？(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
		fp=fopen("users.txt","wt");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LU->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		printf("操作成功\n");
		fclose(fp);
		return;
//	}
	//else
		//printf("已放弃注册");
 }
 void user_moneywrite(link_user LM)
 {
 	FILE *fp;
	user *p;
	char a;
//	printf("是否将信息保存至文件里？(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
		fp=fopen("users.txt","wt");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LM->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		//printf("注册成功\n");
		fclose(fp);
		//return;
//	}
	//else
		//printf("已放弃注册");
 }
 void userwrite2(link_user LU)
 {
 	FILE *fp;
	user *p;
	char a;
	printf("是否将信息保存至文件里？(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("users.txt","at");
		if(fp==NULL)
			printf("错误！无法打开");
		for(p=LU->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		printf("注册成功\n");
		fclose(fp);
		return;
	}
	else
		printf("已放弃注册");
 }
void increaseshop(link_shop LS)
{
	char a[30],b[20],c[15],d[20];
	shop *s;
	printf("请输入你所想加入的店铺信息：\n");
	printf("\t\t●    店铺名称：");
	scanf("%s",a);
	printf("\n\t\t●    店铺电话：");
	scanf("%s",b);
	printf("\n\t\t●    店铺地址：");  
	scanf("%s",c);
	printf("\n\t\t●    店铺密码：");  
	scanf("%s",d);
	if(strcmp(a,"0")!=0)
	{
		s=(shop *)malloc(sizeof(shop));
		strcpy(s->name,a);
		strcpy(s->phone,b);
		strcpy(s->address,c);
		strcpy(s->password,d);
	}
	s->next=LS->next;
	LS->next=s; 
	shopwrite1(LS);
 }
void shopfind(link_shop LS)
{ 
	shop *p;
	char E[20];
	p=LS->next;
	printf("请输入店铺的名称：");
	scanf("%s",E); 
	while(strcmp(p->name,E)!=0&&(p->next)!=NULL)
	{
		p=p->next;
	}
	if((p->next)==NULL)
	{
		printf("没有此店铺");
		return;
	}	 
	printf("您所查询的店铺信息为：\n名称\t电话\t地址\n");
	printf("%s %s %s",p->name,p->phone,p->address);
} 
void registerdeal()
{
	int q;
	FILE *fp;
	char y;
	link_shop head;
	shop *r,*p;
	head=r=(shop *)malloc(sizeof(shop));
	r->next=NULL;
	fp=fopen("shenqing.txt","rt");
	if(fp==NULL)
	{
		printf("发生错误，无法打开文件");
		return; 
	}
	if((y=fgetc(fp))==EOF)
	{
		printf("目前没有需要处理的信息\n");
		system("pause");
		system("cls");
		MENU1();
		return;
	}
	else
	{
		while(!feof(fp))
		{
			p=(shop *)malloc(sizeof(shop));
			fscanf(fp," %s %s %s %s \n",p->name,p->phone,p->address,p->password);
			r->next=p;
			p->next=NULL;
			r=p;
		}
		for(p=head->next;p!=NULL;p=p->next)
			printf("%s %s %s\n",p->name,p->phone,p->address); 
		printf("是否同意注册？Y/else");
		scanf("%*c%c",&y); 
		if(y=='Y')
		{
			fp=fopen("shop.txt","at");
			if(fp==NULL)
				printf("文件不存在，打开错误\n"); 
			for(p=head->next;p!=NULL;p=p->next)
				fprintf(fp,"% s %s %s %s \n",p->name,p->phone,p->address,p->password);
			fclose(fp);
		} 
			
	} 
	printf("处理成功"); 
	fp=fopen("shenqing.txt","wt");
	fclose(fp);
}
void MENU1_choose()
{
	int n,m,q;
	char a[20],b[20],c[20],d[20];
	char y;
	FILE *fp,*fa;
	shop *p;
	shop sq;
	link_shop LS;
	link_user LU;
	LS=shopread();
	while(1)
	{
		printf("请选择你想所想进行的选项:\n"); 
		scanf("%d",&n);
		if(n==1)
		{
			Outputshop(LS);
			printf("是否进行排序？Y/else");
			fflush(stdin);
			y=getchar();
			if(y=='Y')
			{
				system("cls");
				printf("\n\n\n\t\t\t●1.按店铺名称排序\n");
				printf("\t\t\t●2.按店铺地址排序\n");
				scanf("%d",&m);
				if(m==1)
					name_sort(LS);
				if(m==2)
					address_sort(LS);
				printf("1.退出\t2.返回");
				scanf("%d",&m);
				if(m==1)
					exit(0);
				else
				{
					system("cls");
					MENU1();
					continue;
				} 
			}
			else
			{
				printf("已放弃排序\n");
				system("cls");
				MENU1();
			}
				
		}
		if(n==2)
		{
			system("cls");
			printf("\n\n\n\t\t\t☆【1】删除店铺\n");
			printf("\t\t\t☆【2】增加店铺\n");
			printf("\t\t\t☆【3】输入店铺\n");
			printf("\t\t\t☆【0】返回上一级\n");
			printf("\n\t\t请选择将要进行的操作：\n"); //二级 
			while(1)
			{
				scanf("%d",&m);
				if(m==1)
					deleteshop(LS);
				if(m==2)
					increaseshop(LS);
				if(m==3)
				{ 
					LS=creats();
					shopwrite1(LS);
				}
				if(m==4)
					shopfind(LS);	
				if(m==0)
				{
					system("cls");
					MENU1();
					break;
				} 
			}		
		}
		if(n==3)
			registerdeal();//注册处理以及投诉处理函数 
		if(n==4)
		{
			//LU=userread();
			system("cls");
			printf("\n\t请选择所想进行的选项：\n\n");
			printf("\t● ○ ● ○ ● ○  ●\n");
			printf("\t   1.查看个人信息    \n");
			printf("\t○ 2.修改个人信息  ○\n");
			printf("\t   0.返回上一级      \n");//二级 
			printf("\t● ○ ● ○ ● ○  ●\n");
			while(1)
			{
				scanf("%d",&m);
				if(m==1)
				{
					char d[20];
					fa=fopen("admin.txt","rt");
					fscanf(fa,"%s %s %s %s",a,b,c,d);
					fclose(fa);
					printf("\n\t\t地区\t姓名\t电话号码\n");
					printf("\t\t%s\t%s\t%s\n",a,b,d);
				}
				if(m==2)
				{
					system("cls");
					printf("\n                                                          温馨提示，按0返回哦(〃'▽'〃)\n"); 
					printf("\n\t\t● ○ ● ○ ● ○  ●\n");
					printf("\t\t     1.修改姓名      \n");
					printf("\t\t○   2.修改地址    ○\n");
					printf("\t\t     3.修改密码      \n");//三级 
					printf("\t\t● ○ ● ○ ● ○  ●\n");
					scanf("%d",&q); 
					if(q==1)
					{
						printf("请输入新的姓名：\n");
						scanf("%s",b);
					}
					if(q==2)
					{
						printf("请输新的地址：\n");
						scanf("%s",a); 
					} 
					if(q==3)//修改密码，含找回密码 
					{
						int j=0,h; 
						char f[20],e[20];
						fa=fopen("admin.txt","rt");
						fscanf(fa,"%s %s %s %s",a,b,c,d);
						printf("您需要输入旧的密码：\n");
						scanf("%s",f);
						while(strcmp(f,c)!=0)
						{
							j++; 
							printf("\t\t×您的密码有误,请重新输入：");
							scanf("%s",f);
							if(j==2)
							{
								printf("\t\t×您已经连续输错三次，按1找回密码，其他数字键返回:");
								scanf("%d",&j);
								if(j==1)
								{
									printf("请输入您的电话号码:");
									scanf("%s",e);
									if(strcmp(e,d)==0)
									{
										srand((unsigned)time(NULL));
										j=rand()%900+100;
										fp=fopen("yanzheng.txt","wt");
										//fscanf(fp,"%d\n",&j);
										fprintf(fp,"%d\n",j);
										fclose(fp);
										printf("我们已经发送验证码到您的手机，请输入:");
										scanf("%d",&h);
										if(h==j)
										{
											printf("\t\t√请重新设置您的密码:");
											scanf("%s",c);
											break; 
										}
										else
										{
											printf("\t\t×验证码错误\n");
											break; 
										}
									}
									else
									{
										printf("\t\t×找回密码失败\n");
										break; 
									}
								}
								else
								{
									system("cls");
									MENU();
									return; 
								}
									
							}
						}
						if(strcmp(c,f)==0)
						{
							printf("请输入新的密码：\n");
							scanf("%s",c);
						}
					}
					if(q==1||q==2||q==3)
					{
						printf("是否保存？Y/else");
						fflush(stdin);
						y=getchar();
						if(y=='Y')
						{
							fa=fopen("admin.txt","wt");
							fprintf(fa,"%s %s %s %s",a,b,c,d);
							fclose(fa);
							printf("\t\t√保存成功"); 
						}
						else
							printf("\t\t×已放弃修改");
						system("pause");
						system("cls");
						printf("\n\t请选择所想进行的选项：\n\n");
						printf("\t● ○ ● ○ ● ○  ●\n");
						printf("\t   1.查看个人信息    \n");
						printf("\t○ 2.修改个人信息  ○\n");
						printf("\t   0.返回上一级      \n");//二级 
						printf("\t● ○ ● ○ ● ○  ●\n");
						continue; 
					}
					if(q==0)
					{
						system("cls");
						printf("\n\t请选择所想进行的选项：\n\n");
						printf("\t● ○ ● ○ ● ○  ●\n");
						printf("\t   1.查看个人信息    \n");
						printf("\t○ 2.修改个人信息  ○\n");
						printf("\t   0.返回上一级      \n");//二级 
						printf("\t● ○ ● ○ ● ○  ●\n");
						continue;
					}
				}
				if(m==0) 
				{
					system("cls");
					MENU1();
					break;
				} 
			} 
		}
		if(n==5)
		{
			system("cls");
			MENU1();
		}
		if(n==0)
		{
			system("cls");
			MENU();
			break;
		}
		if(n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=0)
		{
			printf("\t\t∷");
			Sleep(400);
			printf("∷");
			Sleep(400);
			printf("∷");
			Sleep(400);
			printf("您需要输入菜单上的数字哦\n"); 
		}	
	}
}
void MENU2_choose()
{
	int n,m,q,i=0;
	char a[20],b[20];
	char y;
	FILE *fp;
	user *u;
	food *p,*s,*r;
	link_food LF,Lf;
	LF=foodread();
	link_user LU;
//	user user;
	while(1)
	{
		scanf("%d",&n);
		switch(n)
		{
			case 1:
					system("cls");
					printf("\n\n\t\t\t请选择需要进行的选项:\n\n");
					printf("\t\t\t--------------------\n");
					printf("\t\t\t    用 户 相 关\n");
					printf("\t\t\t--------------------\n");
					printf("\t\t\t●   1.修改用户名\n"); 
					printf("\t\t\t●   2.修改密码\n"); 
					printf("\t\t\t●   3.修改收货地址\n");
					printf("\t\t\t●   4.修改电话号\n");
					printf("\t\t\t●   5.查看个人信息\n");
					printf("\t\t\t●   6.充值钱包\n");
					printf("\t\t\t●   0.返回上一级\n");
					LU=userread();
					u=LU->next;
					while(1)
					{
						if(strcmp(yh,u->name)==0)
							break;
						else
							u=u->next;
					}
					while(1)
					{
						scanf("%d",&m);
						if(m==1)
						{
							printf("请输入新的用户名：\n");
							scanf("%s",u->name);
						}
						if(m==2)
						{
							printf("您需要输入旧的密码：\n");
							scanf("%s",b);
							while(strcmp(u->password,b)!=0)
							{
								printf("密码错误，请重新输入\n");
							
								scanf("%s",b);
								i++;
								if(i==2)
								{
									printf("您已经输错三次，请5分钟后再试");
									continue; 
								}
							}
							printf("请输入新的密码：");
							scanf("%s",u->password); 
						}
						if(m==3)
						{
							printf("请输入新的收货地址：");
							scanf("%s",u->delivery); 
						}
						if(m==4)
						{ 
							printf("请输入新的收货地址");
							scanf("%s",u->number);
						}
						if(m==1||m==2||m==3||m==4)
							userwrite(LU);
						if(m==5)
						{
							printf("您的信息为：\n");
							printf("姓名\t收获地址\t联系方式\n"); 
							printf("%s\t%s\t%s\n",u->name,u->delivery,u->number);
						}
						if(m==6)
						{
							u=addmoney(u);
							userwrite(LU); 
						}
						if(m==0)
						{
							system("cls");
							MENU2(); 
							break;
						}
						
					} 
					break;
			case 2:
				LF=dingdanread();
				Outputfood(LF);	 
				break;
			case 3:
				LF=foodread();
				system("cls");
				outputfood(LF);
				p=LF->next; 
				printf("\t●   按1购买，其他数字返回\t");
				scanf("%d",&q);
				if(q==1)
				{
					purchase();
				}
				else
				{
					system("cls");
					MENU2();
					continue;
				}
				break;
			case 4:
				LF=dingdanread();
				p=LF->next;
				i=0;		 
				printf("请输入所想修改的订单号：");
				scanf("%d",&n);
				while(p)
				{
					if(n==p->type)
					{
						if(strcmp(p->yonghu,yh)==0)
						{
							i=1; 
							system("cls");
							printf("\n订单信息如下：\n"); 
							printf("\t菜名\t单价\t数量\t总价\t店铺\t用户名\t\n");
							printf("\t%s\t%d\t%d\t%d\t%s\t%s\n\n",p->name,p->price,p->amount,p->total,p->shop,p->yonghu); 
							printf("\t\t○   1.修改数量\n");
							printf("\t\t○   2.删除订单\n");
							printf("\t\t○   其他数字键返回\n"); 
							scanf("%d",&n);
							if(n==1)
							{
								end = time(NULL);
								if((difftime(end,start))<180)
								{
									printf("还没有超过三分钟，请尽快修改哦\n"); 
									printf("您只能修改菜的数量:");
									scanf("%d",&m);
									p->amount=m;
									p->total=(p->amount)*(p->price);
									dingdanwrite(LF);
									printf("\t\t√已成功修改");
								}
								else
								{
									printf("时间超过三分钟，已配送\n");
									system("pause");
									system("cls");
									MENU2(); 
									break;
								}
							}
							if(n==2)
							{
								deletedingdan(LF);
								dingdanwrite(LF); 
							}
							else
							{
								system("pause");
								system("cls");
								MENU2();
								break;
							}
						}
						if(strcmp(p->yonghu,yh)!=0)
						{
							printf("\t\t×   不好意思，该订单您没有权限修改\n");
							i=2;
						    system("pause");  
							system("cls");
							MENU2(); 
							break;
						}
					}
					else
						p=p->next;
				}	
				if(i==0)
				{
					printf("\t\t×没有改订单\n");
					system("pause");
					system("cls");
					MENU2();
					continue;
				}	
				break; 
			case 5:
				purchase();
				break;
			case 6:
				system("cls");
				printf("\n\n\n\t\t\t---------------\n");
				printf("\t\t\t  订 单 排 序\n");
				printf("\t\t\t---------------\n"); 
				printf("\t\t\t△ 1.按菜名排序：\n");
				printf("\t\t\t△ 2.按总价排序：\n");
				printf("\t\t\t△ 0.返回\n");
				scanf("%d",&m);
				{
					LF=dingdanread();
					if(m==1)
						dingdan_name_sort(LF);
					if(m==2)
						dingdan_total_sort(LF);
					if(m==0)
					{
						system("cls");
						MENU2();
						continue;
					}
					system("pause");
					system("cls");
					MENU2();
					continue;
						
				}
				break;
				//dindan_name_sort(LF);
			case 0:
				system("cls");
				MENU();
				return;
				break;
			}
		}
}
void deletefood(link_food Lf)
{
	int i=0;
	food *p,*n;
	p=Lf;
	n=p->next;
	char m[20];
	char a;
	printf("请输入你所想删除的菜名：");
	scanf("%s",m);
	while(n)
	{
		if(strcmp(m,n->name)==0)
		{
			if(strcmp(n->shop,dp)==0)
			{
				i++;
				p->next=n->next;
				foodwrite1(Lf);
			}
			else
			
				printf("不好意思，您没有权限删除\n");
			break;
		}
		else
		{
			p=p->next;
			n=n->next;
		}
	}
	if(i==0)
	{
		printf("没有此菜，无法删除\n");
		return;
	}
}
void MENU3_choose()
{
	int x,y;
	char a[20];
	link_food LF,Lf;
	LF=foodread();
	food *p;
	while(1)
	{
		printf("请选择：");
		scanf("%d",&x);
		if(x==1)
		{
			creatf();
			//foodwrite(LF);
		}
		if(x==2)
		{
			int i=0;
			printf("请输入要修改的菜的名称：");
			scanf("%s",a);
			//LF=foodread();
			p=LF->next;
			while(p!=NULL)
			{
				if(strcmp(a,p->name)==0)
				{
					i++;
					if(strcmp(dp,p->shop)==0)
					{
						printf("请重新输入菜的信息:\n");
						printf("\t\t\t△新菜名：");
						scanf("%s",p->name);
						printf("\t\t\t△新菜价：");
						scanf("%d",&p->price);
						foodwrite1(LF); 
					}
					else
						printf("不好意思，您没有权限修改\n");
					break; 
				}
				p=p->next;
			}
			if(i==0)
				printf("\t\t×   没有此菜的信息\n"); 
		}
		if(x==3)
		{
			deletefood(LF);
		} 
		if(x==4)
		{
			int sum=0;
			Lf=foodread();
			p=Lf->next;
			system("cls");
			printf("\n\n\t\t您家的食物如下：");
			printf("\n\t\t----------------------------------------\n");
			printf("\t\t菜名\t     菜价\t店铺\t    菜系\n");
			printf("\t\t----------------------------------------\n"); 
			while(p)
			{
				if(strcmp(p->shop,dp)==0)
				{
					printf("\t\t%-14s%-10d%-12s%s\n",p->name,p->price,p->shop,p->leibie);
					printf("\t\t----------------------------------------\n");
					sum=sum+1;
				}
				p=p->next;
			}
			printf("\t\t合计/个：\t\t\t%d个菜\n",sum);
			printf("\t\t----------------------------------------\n");
			if(sum==0)
				printf("\t\t\t●   怪不得没订单，您还没添加菜品呢\n");
			system("pause");
			system("cls");
			MENU3();
		}
		if(x==5)
		{
			LF=dingdanread();
			scorefind(LF);//查看业绩函数
			system("pause");
			system("cls");
			MENU3();
		}		 
		if(x==0) 
		{
			system("cls");
			MENU();
			break;
		}	
	} 
}
//登陆
void login()
{
	int n,i=0,j=0;
	char a[10],c[10];
	char b[15],d[15],f[10],e[20];
	FILE *fp;
	char ch;
	system("cls"); 
	MENU();
	printf("请选择：");
	while(1)
	{
		scanf("%d",&n);
		//管理员登陆 
		if(n==1)
		{
			printf("请输入用户名:"); 
			scanf("%s",a);
			printf("请输入密码:");
			while((ch=getch())!=13){
			if(ch==8){
				printf("\b \b");
				i--;
				continue;
			}
			b[i++]=ch;
			putchar('*');
			}
			b[i]='\0';
			fp=fopen("admin.txt","rt");
				if(fp==NULL)
					printf("没有此文件，无法打开");
			fscanf(fp,"%s %s %s %s",f,c,d,e);
			fclose(fp);
			while(strcmp(a,c)!=0||strcmp(b,d)!=0)
			{
				printf("\n账号或密码错误，请重新输入：\n");
				printf("请输入用户名：");
				scanf("%s",a);
				printf("请输入密码：");
				i=0;
				while((ch=getch())!=13){
				if(ch==8){
					printf("\b \b");
					i--;
					continue;
				}
				b[i++]=ch;
				putchar('*');
				}
				b[i]='\0';
				j++;
				if(j==2)
				{
					printf("\n密码错误已达三次,将自动退回主菜单\n");
					system("pause"); 
					system("cls");
					MENU();
					return;
				}
			}
			system("cls");
			//system("color 03");
			welcome();
			printf("\n");
			system("pause");
			system("cls");
			MENU1();
			MENU1_choose(); 
		}
	//用户登录 
		if(n==2)
		{
			link_user LU;
			user *p;
			LU=userread();
			p=LU->next;
			printf("请输入账号或名称");
			scanf("%s",yh);
			printf("请输入密码：");
			i=0;
			while((ch=getch())!=13){
			if(ch==8){
				printf("\b \b");
				i--;
				continue;
			}
			b[i++]=ch;
			putchar('*');
			}
			b[i]='\0';
			int i=0;
			while(p!=NULL)
			{
				if(strcmp(yh,p->name)==0&&strcmp(b,p->password)==0)
				{
					system("cls");
					//system("color 0a");
					//welcome();
					printf("\n");
					system("pause");
					system("cls");
					i++;
					MENU2();
					MENU2_choose();
					break;
				}
				p=p->next;
			}
			if(i==0)
			{ 
				printf("密码或者账号错误\n");
				system("pause");
				system("cls");
				ME();
				return;
			}
		}
		if(n==3)
		{
			link_shop LS;
			shop *p;
			j=0;
			LS=shopread();
			p=LS->next;
			printf("请输入店铺名称或者账号：");
			scanf("%s",dp);
			printf("请输入密码");
			i=0;
			while((ch=getch())!=13)
			{
				if(ch==8)
				{
					printf("\b \b");
					i--;
					continue;
				}		
				putchar('*');
				b[i++]=ch;
			}
			b[i]='\0';
			while(p!=NULL)
			{
				if(strcmp(dp,p->name)==0&&strcmp(b,p->password)==0)
				{
					system("cls");
					//system("color 0a");
					//welcome();
					j++;
					printf("\n");
					system("pause");
					system("cls");
					MENU3();
					MENU3_choose();
					break;
				}
				else
					p=p->next;
			}
			if(j==0)
			{ 
				printf("\t\t\n×   密码或者账号错误\n");
				system("pause");
				system("cls");
				ME();
				return;
			}
		}
		if(n==0)
		{
			system("cls");
			ME();
			break; 
		}	
	}
}
user * creatu()
{
	char a[30],b[20],c[15],d[20];
	char ca[20],mi1[20],mi2[20];
	link_user LU,lu;
	FILE *fp;
	user *s,*r,*p;
	int x,y,i,h; 
	LU=r=(user *)malloc(sizeof(user));
	LU->next=NULL;
	printf("请输入姓名：");
	scanf("%s",a);
	lu=userread();
	while(1)
	{
		i=0;
		p=lu->next;
		while(p)
		{ 
			if(strcmp(a,p->name)==0)
			{
				i++;
				printf("\t\t×此用户已经有人注册过,请重新输入:");
				scanf("%s",a);
				break;
			}
			else
				p=p->next;
		}
		if(i==0)
			break;
	}
	printf("请输入收货地址：");
	scanf("%s",b); 
	printf("请输入密码：");
	scanf("%s",c);
	printf("请输入电话号码：");
	scanf("%s",d); 
	x=strlen(c);
	while(x<8)
	{
		printf("\t\t●   您的密码小于8位，安全指数为低\n");
		printf("按1修改,其他键放弃修改:");
		scanf("%d",&y);
		if(y==1)
		{
			scanf("%s",c);
			x=strlen(c);	
		}
		else
			break;	
	}
	if(strcmp(b,"0")!=0)
	{
		s=(user *)malloc(sizeof(user));
		s->score=0;
		strcpy(s->name,a);
		strcpy(s->delivery,b);
		strcpy(s->password,c);
		strcpy(s->number,d);
		r->next=s;
		s->next=NULL;
		r=s;
		printf("为了方便充值钱包，请绑定您的银行卡：");
		scanf("%s",ca);
		h=strlen(ca);
		while(h<15)
		{
			printf("\t\t●   您的银行卡不足15位，请重新输入：");
			scanf("%s",ca);
			h=strlen(ca); 
		}
		i=0; 
		printf("请设置您的支付密码");
		scanf("%s",mi1);
		printf("请确认密码");
		scanf("%s",mi2);
		if(strcmp(mi1,mi2)!=0)
		{
			printf("\t\t×注册失败,两次密码不同");
			return 0;
		}
		fp=fopen("yue.txt","at");
		fprintf(fp,"%s %s %s\n",a,ca,mi1);
		fclose(fp);
	}
	else
	{
		printf("\t\t×注册失败，请输入正确的收货信息：");
		return 0;
	}
	return LU; 	 
}
void Register()
{
	int y;
	char a;
	FILE *fp;
	shop sq;//申请 
	system("cls");
	printf("\n\n\n\t\t\t\t1.注册用户\t\t\t2.申请店铺\n");
	printf("\t\t\t\t0.返回上一级");
	while(1)
	{
		printf("\t\t▲  请选择要进行的选项："); 
		scanf("%d",&y);
		if(y==1)//用户注册 
		{
			link_user LU;
			LU=creatu(); 
			userwrite2(LU);
		}
		if(y==2)
		{
			printf("请输入店铺名称：");
			scanf("%s",sq.name);
			printf("请输入店铺电话：");
			scanf("%s",sq.phone);
			printf("请输入店铺地址：");
			scanf("%s",sq.address); 
			printf("请输入店铺密码：");
			scanf("%s",sq.password);
			fp=fopen("shenqing.txt","at");
			if(fp==NULL)
			{
				printf("发生错误，无法打开文件");
				return; 
			}
			printf("是否保存？Y/else");
			scanf("%*c%c",&a);
			if(a=='Y')
			{	
				fprintf(fp," %s %s %s %s \n",sq.name,sq.phone,sq.address,sq.password);
				fclose(fp);
				printf("\t\t√   申请成功，等待上级审核"); 
			}
			else
			{
				printf("\t\t×   已放弃申请");
				fclose(fp); 
			}
		}
		if(y==0)
		{
			system("cls");
			printf("\t\tWELCOME\n这里是外卖管理系统，请选择接下来的操作：");
			printf("\n\n\t\t\t\t1.登陆");
			printf("\t\t\t\t2.注册\n"); 
			break;		
		}
	}
}
void choose()
{
	int x;
	ME();
	while(1)
	{
		scanf("%d",&x);
		if(x==1)
			login();
		if(x==0)
		{
			Exit();
			return;
		}
			 
		if(x==2)
			Register();
	}
}
int main()
{
	choose(); 
}

