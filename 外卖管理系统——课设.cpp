#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<windows.h>
#include<time.h>
#include<conio.h>
void choose();
//�������ڵ��̵Ľṹ�� 
typedef struct shop
{
	char name[20];
	char phone[20];
	char address[30];
	char password[20];
	struct shop *next;
}shop,*link_shop;
//�������ڶ����Ľṹ�� 
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
//���������û��Ľṹ��
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
char yh[20];//�û�����ȫ�ֱ��� 
char dp[20];//��������ȫ�ֱ���  
time_t start,end;
//��������
void foodwrite(link_food LF);
void shopwrite1(link_shop LS);
void dingdanwrite(link_food LF);
void user_moneywrite(link_user LM);
void welcome()
{
	int i=0;
	char a[52]="����WELCOME TO RESTAURANT MANAGEMENT SYSTEM����";
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
	printf("\n\n\n\t\t���  W E L C O M E  ���\n\n\t��������������ϵͳ����ѡ��������Ĳ�����");
	printf("\n\n\t\t\t1.��½");
	printf("\t\t\t2.ע��\t\t\t0.�˳�\n"); 
}
//���˵�����½����ע�ᣩ	
void MENU()
{
	printf("\n\n\n\n\t\t\t\t\t================================\n");
	printf("\t\t\t\t\t     ��  ��  ��  ��  ϵ  ͳ     \n");
	printf("\t\t\t\t\t          1.����Ա��½          \n");
	printf("\t\t\t\t\t          2.�û���¼            \n");
	printf("\t\t\t\t\t          3.��ҵ�½            \n");
	printf("\t\t\t\t\t          0.������һ��          \n");
	printf("\t\t\t\t\t================================\n");
}
//����Աѡ�� 
void MENU1()
{
	system("color 0f");
	printf("                                                                         ��ܰС��ʾ����5��������Ŷ^-^\n");
	printf("\n\n\t\t\t\t\t1.�鿴������Ϣ��\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t2.������Ϣ�޸Ĩ�\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t3.����������̡�\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t4.�޸ı�����Ϣ��\n");
	printf("\t\t\t\t\t--------------\n");
	printf("\t\t\t\t\t0.������һ��  ��\n");
}
//�û�ѡ�� 
void MENU2()
{
	system("color 0f");
	printf("\n\n\t\t\t\t 1.�û���� ��\t\t\t 5.�����Ʒ ��\n"); 
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 2.�鿴���� ��\t\t\t 6.��������\n");
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 3.�鿴��Ʒ ��\t\t\t 0.�����ϼ� ��\n");
	printf("\t\t\t\t---------------\t\t\t---------------\n");
	printf("\t\t\t\t 4.�޸Ķ��� ��\n");
}
//����ѡ�� 
void MENU3()
{
	system("color 0f");
	printf("\n\n\n\t\t\t ________ Shop Version _______\n");
	printf("\t\t\t|                             |\n");
	printf("\t\t\t|          1.��Ӳ�Ʒ         |\n");
	printf("\t\t\t|          2.�޸Ĳ�Ʒ         |\n");
	printf("\t\t\t|          3.ɾ����Ʒ         |\n");
	printf("\t\t\t|          4.�鿴��Ʒ         |\n");
	printf("\t\t\t|          5.�鿴ҵ��         |\n");
	printf("\t\t\t|          0.������һ��       |\n");
	printf("\t\t\t|_____________________________|\n");
}
//�������ڵ�����
void *creatf()
{
	int i=0,n;
	link_food LF;
	food *s,*r;
	char a[10];
	//srand((unsigned)time(NULL));//��������������� 
	LF=(food *)malloc(sizeof(food));
	LF->next=NULL;
	r=LF;
	while(1)
	{
		printf("������˵����ƣ�");
		scanf("%s",a);
		if(strcmp(a,"0")!=0)
		{
			s=(food *)malloc(sizeof(food));
			printf("������˵ĵ��ۣ�");
			scanf("%d",&s->price);
			printf("������˵����");
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
		printf("�����������Ϣ:\n");
		printf("\t\t��    �������ƣ�");
		scanf("%s",a);
		printf("\n\t\t��    ���̵绰��");
		scanf("%s",b);
		if(strcmp(b,"0")!=0)
		{
			printf("\n\t\t��    ���̵�ַ��");  
			scanf("%s",c);
			printf("\n\t\t��    �������룺");  
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
	printf("��פ���̼����£�\n");
	printf("\t\t\t\t-------------------------------------------\n");
	printf("\t\t\t\t��������\t���̵绰\t���̵�ַ\n");
	printf("\t\t\t\t-------------------------------------------\n");
	while(p)
	{
		printf("\t\t\t\t%8s\t%8s\t%7s\n",p->name,p->phone,p->address);
		printf("\t\t\t\t-------------------------------------------\n");
		p=p->next;
	}
	for(u =Ls->next; u != NULL;u = u->next)  
        n++;
    printf("\t\t\t\t�ϼ�\t\t\t\t%d��\n",n);
    printf("\t\t\t\t-------------------------------------------\n");
}
void Outputfood(link_food LF)
{
	food *s;
	s=LF->next;
	int sum=0;
	printf("�������£�\n");
	printf("\t----------------------------------------------------------------------------------------------------\n");
	printf("\t����\t\t����/��\t\t����/Ԫ\t\t�ܼ�/Ԫ\t\t����\t\t������\t\t�û���\n"); 
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
	printf("\t�ۼ����/Ԫ\t\t\t\t\t\t\t%d\n",sum);
	printf("\t----------------------------------------------------------------------------------------------------\n");
	if(sum==0)
	{  
		printf("��   ����û�ж����أ���ȥ�����  ��(>��<*) ");
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
	printf("\n\t\t\t                 ��       ��                        "); 
	printf("\n\t\t\t--------------------------------------------------\n");
	printf("\t\t\t����        �˼�         ����           ��ϵ\n"); 
	printf("\t\t\t---------------------------------------------------\n");
	while(p)
	{
		printf("\t\t\t%-13s%-12d%-14s%s\n",p->name,p->price,p->shop,p->leibie);
		printf("\t\t\t---------------------------------------------------\n");
		p=p->next;
	}
}
//��ֵ
user* addmoney(user *u)
{
	int n;
	char y;
	char a[20];
	FILE *fp;
	link_money LY;
	money *p,*r;
	printf("���˻�������Ϊ��%d",u->score);
	printf("�Ƿ��ֵ��Y/else");
	fflush(stdin);//������� 
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
		printf("��ֵ��Ǯ����");
		scanf("%d",&n);
		printf("������֧�����룺");
		scanf("%s",a);
		if(strcmp(p->mima,a)==0)
		{
			u->score=(u->score+n); 
			printf("�ѳ�ֵ");
		} 
		else
			printf("\t\t��   ������󣬳�ֵʧ��");
	}
	else
		printf("�ѷ�����ֵ");
	return u; 
}					
//����������
void name_sort(link_shop LS)  
{  
    int i,j,n;  
    n = 0;  //��¼����������
    shop *u,*q,*p;
    for(u =LS->next; u != NULL;u = u->next)  
        n++;  
//����ð�ݷ��Ը����ڵ㰴��������
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
	printf("\t����������Ϣ\n");
	Outputshop(LS);
	return;
}
void address_sort(link_shop LS)  
{  
    int i,j,n;  
    n = 0;  //��¼����������
    shop *u,*q,*p;
    for(u =LS->next; u != NULL;u = u->next)  
        n++;  
//����ð�ݷ��Ը����ڵ㰴��ַ����
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
	printf("\t\t\t\t��ַ����������Ϣ\n");
	Outputshop(LS);
	return;
}
void dingdan_name_sort(link_food LF)  //������ʳ���������� 
{  
    int i,j,n;  
    n = 0;  //��¼����������
    food *u,*q,*p;
    for(u =LF->next; u != NULL;u = u->next)  
        n++;  
//����ð�ݷ��Ը����ڵ㰴��������
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
void dingdan_total_sort(link_food LF)  //�������ܼ۴Ӹߵ������� 
{  
    int i,j,n;  
    n = 0;  //��¼����������
    food *u,*q,*p;
    for(u =LF->next; u != NULL;u = u->next)  
        n++;  
//����ð�ݷ��Ը����ڵ㰴��������
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
	printf("������������ɾ���Ķ�����ţ�");
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
				printf("������˼����û��Ȩ��ɾ��\n");
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
		printf("�鿴����ʧ��");
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
	printf("\n\n\n\t\t\t�����Ķ�������:\n");
	printf("      ----------------------------------------------------------------------------------------------------\n");
	printf("      ��Ʒ���� \t��Ʒ����\t��Ʒ����\t��Ʒ�ܼ�\t��������\t������ \t\t�û���\n");
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
	printf("      �ϼ�/Ԫ��\t\t\t\t\t\t\t�ۼ�����%d\n",sum);
	printf("      ----------------------------------------------------------------------------------------------------\n");
	if(sum==0)
		printf("\t\t��   ������Ĳ˻�û���˹���Ŷ��Ӧ�÷�˼��\n");
}
food * foodread()//��ȡ 
{
	link_food LF;
	food *s,*r;
	LF=r=(food *)malloc(sizeof(food));
	LF->next=NULL;
	FILE *fp;
	fp=fopen("food.txt","rt");
	if(fp==NULL)
	{
		printf("���ܴ򿪴��ļ�");
		exit(1); 
	}
	while(!feof(fp))//�ж��ļ�ָ���Ƿ����ļ�����λ�ã����ǣ�����1���ǣ�����0 
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
money * moneyread()//��ȡ 
{
	link_money LM;
	money *s,*r;
	LM=r=(money *)malloc(sizeof(money));
	LM->next=NULL;
	FILE *fp;
	fp=fopen("yue.txt","rt");
	if(fp==NULL)
	{
		printf("���ܴ򿪴��ļ�");
		exit(1); 
	}
	while(!feof(fp))//�ж��ļ�ָ���Ƿ����ļ�����λ�ã����ǣ�����1���ǣ�����0 
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
		printf("���ܴ򿪴��ļ�");
		exit(1); 
	}
	while(!feof(fp))//�ж��ļ�ָ���Ƿ����ļ�����λ�ã����ǣ�����1���ǣ�����0 
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
		printf("���ܴ򿪴��ļ�");
		exit(1); 
	}
	while(!feof(fp))//�ж��ļ�ָ���Ƿ����ļ�����λ�ã����ǣ�����1���ǣ�����0 
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
	printf("������������ɾ���ĵ������ƻ��ߵ绰��");
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
		printf("û�д˵��̣��޷�ɾ��\n");
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
	printf("������������ɾ���Ķ����ţ�");
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
				printf("������˼����û��Ȩ��ɾ��\n");
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
		printf("\tû�д˶������޷�ɾ��\n");
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
	printf("\t\t�������ɶ�أ�");
	scanf("%s",a);
	Lf=foodread();
	food *p;
	p=Lf->next;
	srand((unsigned)time(NULL));//�����ŵ����� 
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
		printf("\t\t\t��������˼����û�д˲���\n");
		system("pause");
		system("cls");
		MENU2();
		return; 
	}
	else
	{
		p=Lf->next;
		printf("\n\t\t\t--------------------------------------------------\n");
		printf("\t\t\t����        �˼�         ����           ��ϵ\n"); 
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
	printf("\t\t��������Ҫ����ĵ��̣�");
	scanf("%s",b);
	lu=userread();
	us=lu->next;
	while(us)
	{
		if(strcmp(yh,us->name)==0)
			break;
		else
			us=us->next;
	}//�ҳ�Ҫ������û���Ϣ 
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
	}//�ҳ��û������п���Ϣ 
	if(i==0)
	{
		printf("\t\t��   ����û�а����п�Ŷ�����ܹ����");
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
				printf("\t\t��������Ҫ���������");
				scanf("%d",&p->amount);
				if(p->amount!=0)
				{
					i++;
					p->total=(p->amount)*(p->price);
					p->type=rand()%900+100;
					if((us->score)<p->total)
					{
						printf("\t\t��   �����˺����㣬���ȳ�ֵ\n");
						system("pause");
						system("cls");
						MENU2();
						return;
					}
					printf("\t\t��ȷ�Ϲ���Y/else");
					fflush(stdin);
					y=getchar();
					if(y=='Y')
					{
						printf("������֧������:");
						scanf("%s",mi);
						if(strcmp(mi,mo->mima)==0)
						{
							fp=fopen("dingdan.txt","at");
							if(fp==NULL)
								printf("\t\t\t\t������ʧ��\n");//���ļ��޷��򿪶�ʧ��
							else
							{
								fprintf(fp,"%s %d %d %d %s %d %s\n",p->name,p->amount,p->price,p->total,p->shop,p->type,yh);
								fclose(fp);
								us->score=(us->score)-(p->total);
								user_moneywrite(lu);
								printf("\t\t\t\t�̹���ɹ��������ĵȴ�����\n");
								start = time(NULL);//��ʱ 
								system("pause");
								system("cls");
								MENU2();
								return;
							}		
						}
						else
						{
							printf("\t\t��   ������󣬹���ʧ��");
							system("pause");
							system("cls");
							MENU2();
							return;  
						}		 
					} 
					else
					{
						printf("\t\t\t���ѷ�������");
						system("pause");
						system("cls");
						MENU2();
						return; 
					}
				}
				else
				{
					printf("\t\t\t����������ȷ������");
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
		printf("\t\t����������еĵ�������Ŷ\n");
		system("pause");
		system("cls");
		MENU2(); 
	}
}
void foodwrite(link_food LF)//���� 
 {
 	FILE *fp;
	food *p;
	char a;
	printf("ȷ�ϱ��棿(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("food.txt","at");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %s %s\n",p->name,p->price,dp,p->leibie);
		printf("�޸ĳɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ����޸�");
 }
 void foodwrite1(link_food LF)
 {
 	FILE *fp;
	food *p;
	char a;
	printf("ȷ�ϱ��棿(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("food.txt","wt");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %s %s\n",p->name,p->price,p->shop,p->leibie);
		printf("�޸ĳɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ����޸�");
 }
// void foodwrite2(link_food LF)
// {
// 	FILE *fp;
//	food *p;
//	char a;
//	printf("ȷ�ϱ��棿(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
//		fp=fopen("food.txt","wt");
//		if(fp==NULL)
//			printf("�����޷���");
//		for(p=LF->next;p!=NULL;p=p->next)
//			fprintf(fp,"%s %d %s %s\n",p->name,p->price,p->shop,p->leibie);
//		printf("�޸ĳɹ�\n");
//		fclose(fp);
//		return;
//	}
//	else
//		printf("�ѷ����޸�");
// }
 void dingdanwrite(link_food LF)
 {
 	FILE *fp;
	food *p;
	char a;
	printf("ȷ�ϱ��棿(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("dingdan.txt","wt");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LF->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %d %d %d %s %d %s\n",p->name,p->amount,p->price,p->total,p->shop,p->type,p->yonghu);
		printf("�޸ĳɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ����޸�"); 
 }
void shopwrite1(link_shop LS)
 {
 	FILE *fp;
	shop *p;
	char a;
	printf("ȷ�ϱ��棿(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("shop.txt","wt");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LS->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s\n",p->name,p->phone,p->address,p->password);
		printf("����ɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ���");
 }
 void shopwrite2(link_shop LS)
 {
 	FILE *fp;
	shop *p;
	char a;
	printf("�Ƿ���Ϣ�������ļ��(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("shop.txt","at");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LS->next;p!=NULL;p=p->next)
		fprintf(fp,"%s %s %s\n",p->name,p->phone,p->address);
		printf("�޸ĳɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ����޸�");
	 
 }
 void userwrite(link_user LU)
 {
 	FILE *fp;
	user *p;
	char a;
//	printf("��ȷ�ϣ�(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
		fp=fopen("users.txt","wt");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LU->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		printf("�����ɹ�\n");
		fclose(fp);
		return;
//	}
	//else
		//printf("�ѷ���ע��");
 }
 void user_moneywrite(link_user LM)
 {
 	FILE *fp;
	user *p;
	char a;
//	printf("�Ƿ���Ϣ�������ļ��(Y/else)");
//	scanf("%*c%c",&a);
//	if(a=='Y')
//	{
		fp=fopen("users.txt","wt");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LM->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		//printf("ע��ɹ�\n");
		fclose(fp);
		//return;
//	}
	//else
		//printf("�ѷ���ע��");
 }
 void userwrite2(link_user LU)
 {
 	FILE *fp;
	user *p;
	char a;
	printf("�Ƿ���Ϣ�������ļ��(Y/else)");
	scanf("%*c%c",&a);
	if(a=='Y')
	{
		fp=fopen("users.txt","at");
		if(fp==NULL)
			printf("�����޷���");
		for(p=LU->next;p!=NULL;p=p->next)
			fprintf(fp,"%s %s %s %s %d\n",p->name,p->delivery,p->password,p->number,p->score);
		printf("ע��ɹ�\n");
		fclose(fp);
		return;
	}
	else
		printf("�ѷ���ע��");
 }
void increaseshop(link_shop LS)
{
	char a[30],b[20],c[15],d[20];
	shop *s;
	printf("���������������ĵ�����Ϣ��\n");
	printf("\t\t��    �������ƣ�");
	scanf("%s",a);
	printf("\n\t\t��    ���̵绰��");
	scanf("%s",b);
	printf("\n\t\t��    ���̵�ַ��");  
	scanf("%s",c);
	printf("\n\t\t��    �������룺");  
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
	printf("��������̵����ƣ�");
	scanf("%s",E); 
	while(strcmp(p->name,E)!=0&&(p->next)!=NULL)
	{
		p=p->next;
	}
	if((p->next)==NULL)
	{
		printf("û�д˵���");
		return;
	}	 
	printf("������ѯ�ĵ�����ϢΪ��\n����\t�绰\t��ַ\n");
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
		printf("���������޷����ļ�");
		return; 
	}
	if((y=fgetc(fp))==EOF)
	{
		printf("Ŀǰû����Ҫ�������Ϣ\n");
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
		printf("�Ƿ�ͬ��ע�᣿Y/else");
		scanf("%*c%c",&y); 
		if(y=='Y')
		{
			fp=fopen("shop.txt","at");
			if(fp==NULL)
				printf("�ļ������ڣ��򿪴���\n"); 
			for(p=head->next;p!=NULL;p=p->next)
				fprintf(fp,"% s %s %s %s \n",p->name,p->phone,p->address,p->password);
			fclose(fp);
		} 
			
	} 
	printf("����ɹ�"); 
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
		printf("��ѡ������������е�ѡ��:\n"); 
		scanf("%d",&n);
		if(n==1)
		{
			Outputshop(LS);
			printf("�Ƿ��������Y/else");
			fflush(stdin);
			y=getchar();
			if(y=='Y')
			{
				system("cls");
				printf("\n\n\n\t\t\t��1.��������������\n");
				printf("\t\t\t��2.�����̵�ַ����\n");
				scanf("%d",&m);
				if(m==1)
					name_sort(LS);
				if(m==2)
					address_sort(LS);
				printf("1.�˳�\t2.����");
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
				printf("�ѷ�������\n");
				system("cls");
				MENU1();
			}
				
		}
		if(n==2)
		{
			system("cls");
			printf("\n\n\n\t\t\t�1��ɾ������\n");
			printf("\t\t\t�2�����ӵ���\n");
			printf("\t\t\t�3���������\n");
			printf("\t\t\t�0��������һ��\n");
			printf("\n\t\t��ѡ��Ҫ���еĲ�����\n"); //���� 
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
			registerdeal();//ע�ᴦ���Լ�Ͷ�ߴ����� 
		if(n==4)
		{
			//LU=userread();
			system("cls");
			printf("\n\t��ѡ��������е�ѡ�\n\n");
			printf("\t�� �� �� �� �� ��  ��\n");
			printf("\t   1.�鿴������Ϣ    \n");
			printf("\t�� 2.�޸ĸ�����Ϣ  ��\n");
			printf("\t   0.������һ��      \n");//���� 
			printf("\t�� �� �� �� �� ��  ��\n");
			while(1)
			{
				scanf("%d",&m);
				if(m==1)
				{
					char d[20];
					fa=fopen("admin.txt","rt");
					fscanf(fa,"%s %s %s %s",a,b,c,d);
					fclose(fa);
					printf("\n\t\t����\t����\t�绰����\n");
					printf("\t\t%s\t%s\t%s\n",a,b,d);
				}
				if(m==2)
				{
					system("cls");
					printf("\n                                                          ��ܰ��ʾ����0����Ŷ(��'��'��)\n"); 
					printf("\n\t\t�� �� �� �� �� ��  ��\n");
					printf("\t\t     1.�޸�����      \n");
					printf("\t\t��   2.�޸ĵ�ַ    ��\n");
					printf("\t\t     3.�޸�����      \n");//���� 
					printf("\t\t�� �� �� �� �� ��  ��\n");
					scanf("%d",&q); 
					if(q==1)
					{
						printf("�������µ�������\n");
						scanf("%s",b);
					}
					if(q==2)
					{
						printf("�����µĵ�ַ��\n");
						scanf("%s",a); 
					} 
					if(q==3)//�޸����룬���һ����� 
					{
						int j=0,h; 
						char f[20],e[20];
						fa=fopen("admin.txt","rt");
						fscanf(fa,"%s %s %s %s",a,b,c,d);
						printf("����Ҫ����ɵ����룺\n");
						scanf("%s",f);
						while(strcmp(f,c)!=0)
						{
							j++; 
							printf("\t\t��������������,���������룺");
							scanf("%s",f);
							if(j==2)
							{
								printf("\t\t�����Ѿ�����������Σ���1�һ����룬�������ּ�����:");
								scanf("%d",&j);
								if(j==1)
								{
									printf("���������ĵ绰����:");
									scanf("%s",e);
									if(strcmp(e,d)==0)
									{
										srand((unsigned)time(NULL));
										j=rand()%900+100;
										fp=fopen("yanzheng.txt","wt");
										//fscanf(fp,"%d\n",&j);
										fprintf(fp,"%d\n",j);
										fclose(fp);
										printf("�����Ѿ�������֤�뵽�����ֻ���������:");
										scanf("%d",&h);
										if(h==j)
										{
											printf("\t\t��������������������:");
											scanf("%s",c);
											break; 
										}
										else
										{
											printf("\t\t����֤�����\n");
											break; 
										}
									}
									else
									{
										printf("\t\t���һ�����ʧ��\n");
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
							printf("�������µ����룺\n");
							scanf("%s",c);
						}
					}
					if(q==1||q==2||q==3)
					{
						printf("�Ƿ񱣴棿Y/else");
						fflush(stdin);
						y=getchar();
						if(y=='Y')
						{
							fa=fopen("admin.txt","wt");
							fprintf(fa,"%s %s %s %s",a,b,c,d);
							fclose(fa);
							printf("\t\t�̱���ɹ�"); 
						}
						else
							printf("\t\t���ѷ����޸�");
						system("pause");
						system("cls");
						printf("\n\t��ѡ��������е�ѡ�\n\n");
						printf("\t�� �� �� �� �� ��  ��\n");
						printf("\t   1.�鿴������Ϣ    \n");
						printf("\t�� 2.�޸ĸ�����Ϣ  ��\n");
						printf("\t   0.������һ��      \n");//���� 
						printf("\t�� �� �� �� �� ��  ��\n");
						continue; 
					}
					if(q==0)
					{
						system("cls");
						printf("\n\t��ѡ��������е�ѡ�\n\n");
						printf("\t�� �� �� �� �� ��  ��\n");
						printf("\t   1.�鿴������Ϣ    \n");
						printf("\t�� 2.�޸ĸ�����Ϣ  ��\n");
						printf("\t   0.������һ��      \n");//���� 
						printf("\t�� �� �� �� �� ��  ��\n");
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
			printf("\t\t��");
			Sleep(400);
			printf("��");
			Sleep(400);
			printf("��");
			Sleep(400);
			printf("����Ҫ����˵��ϵ�����Ŷ\n"); 
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
					printf("\n\n\t\t\t��ѡ����Ҫ���е�ѡ��:\n\n");
					printf("\t\t\t--------------------\n");
					printf("\t\t\t    �� �� �� ��\n");
					printf("\t\t\t--------------------\n");
					printf("\t\t\t��   1.�޸��û���\n"); 
					printf("\t\t\t��   2.�޸�����\n"); 
					printf("\t\t\t��   3.�޸��ջ���ַ\n");
					printf("\t\t\t��   4.�޸ĵ绰��\n");
					printf("\t\t\t��   5.�鿴������Ϣ\n");
					printf("\t\t\t��   6.��ֵǮ��\n");
					printf("\t\t\t��   0.������һ��\n");
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
							printf("�������µ��û�����\n");
							scanf("%s",u->name);
						}
						if(m==2)
						{
							printf("����Ҫ����ɵ����룺\n");
							scanf("%s",b);
							while(strcmp(u->password,b)!=0)
							{
								printf("�����������������\n");
							
								scanf("%s",b);
								i++;
								if(i==2)
								{
									printf("���Ѿ�������Σ���5���Ӻ�����");
									continue; 
								}
							}
							printf("�������µ����룺");
							scanf("%s",u->password); 
						}
						if(m==3)
						{
							printf("�������µ��ջ���ַ��");
							scanf("%s",u->delivery); 
						}
						if(m==4)
						{ 
							printf("�������µ��ջ���ַ");
							scanf("%s",u->number);
						}
						if(m==1||m==2||m==3||m==4)
							userwrite(LU);
						if(m==5)
						{
							printf("������ϢΪ��\n");
							printf("����\t�ջ��ַ\t��ϵ��ʽ\n"); 
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
				printf("\t��   ��1�����������ַ���\t");
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
				printf("�����������޸ĵĶ����ţ�");
				scanf("%d",&n);
				while(p)
				{
					if(n==p->type)
					{
						if(strcmp(p->yonghu,yh)==0)
						{
							i=1; 
							system("cls");
							printf("\n������Ϣ���£�\n"); 
							printf("\t����\t����\t����\t�ܼ�\t����\t�û���\t\n");
							printf("\t%s\t%d\t%d\t%d\t%s\t%s\n\n",p->name,p->price,p->amount,p->total,p->shop,p->yonghu); 
							printf("\t\t��   1.�޸�����\n");
							printf("\t\t��   2.ɾ������\n");
							printf("\t\t��   �������ּ�����\n"); 
							scanf("%d",&n);
							if(n==1)
							{
								end = time(NULL);
								if((difftime(end,start))<180)
								{
									printf("��û�г��������ӣ��뾡���޸�Ŷ\n"); 
									printf("��ֻ���޸Ĳ˵�����:");
									scanf("%d",&m);
									p->amount=m;
									p->total=(p->amount)*(p->price);
									dingdanwrite(LF);
									printf("\t\t���ѳɹ��޸�");
								}
								else
								{
									printf("ʱ�䳬�������ӣ�������\n");
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
							printf("\t\t��   ������˼���ö�����û��Ȩ���޸�\n");
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
					printf("\t\t��û�иĶ���\n");
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
				printf("\t\t\t  �� �� �� ��\n");
				printf("\t\t\t---------------\n"); 
				printf("\t\t\t�� 1.����������\n");
				printf("\t\t\t�� 2.���ܼ�����\n");
				printf("\t\t\t�� 0.����\n");
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
	printf("������������ɾ���Ĳ�����");
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
			
				printf("������˼����û��Ȩ��ɾ��\n");
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
		printf("û�д˲ˣ��޷�ɾ��\n");
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
		printf("��ѡ��");
		scanf("%d",&x);
		if(x==1)
		{
			creatf();
			//foodwrite(LF);
		}
		if(x==2)
		{
			int i=0;
			printf("������Ҫ�޸ĵĲ˵����ƣ�");
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
						printf("����������˵���Ϣ:\n");
						printf("\t\t\t���²�����");
						scanf("%s",p->name);
						printf("\t\t\t���²˼ۣ�");
						scanf("%d",&p->price);
						foodwrite1(LF); 
					}
					else
						printf("������˼����û��Ȩ���޸�\n");
					break; 
				}
				p=p->next;
			}
			if(i==0)
				printf("\t\t��   û�д˲˵���Ϣ\n"); 
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
			printf("\n\n\t\t���ҵ�ʳ�����£�");
			printf("\n\t\t----------------------------------------\n");
			printf("\t\t����\t     �˼�\t����\t    ��ϵ\n");
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
			printf("\t\t�ϼ�/����\t\t\t%d����\n",sum);
			printf("\t\t----------------------------------------\n");
			if(sum==0)
				printf("\t\t\t��   �ֲ���û����������û��Ӳ�Ʒ��\n");
			system("pause");
			system("cls");
			MENU3();
		}
		if(x==5)
		{
			LF=dingdanread();
			scorefind(LF);//�鿴ҵ������
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
//��½
void login()
{
	int n,i=0,j=0;
	char a[10],c[10];
	char b[15],d[15],f[10],e[20];
	FILE *fp;
	char ch;
	system("cls"); 
	MENU();
	printf("��ѡ��");
	while(1)
	{
		scanf("%d",&n);
		//����Ա��½ 
		if(n==1)
		{
			printf("�������û���:"); 
			scanf("%s",a);
			printf("����������:");
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
					printf("û�д��ļ����޷���");
			fscanf(fp,"%s %s %s %s",f,c,d,e);
			fclose(fp);
			while(strcmp(a,c)!=0||strcmp(b,d)!=0)
			{
				printf("\n�˺Ż�����������������룺\n");
				printf("�������û�����");
				scanf("%s",a);
				printf("���������룺");
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
					printf("\n��������Ѵ�����,���Զ��˻����˵�\n");
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
	//�û���¼ 
		if(n==2)
		{
			link_user LU;
			user *p;
			LU=userread();
			p=LU->next;
			printf("�������˺Ż�����");
			scanf("%s",yh);
			printf("���������룺");
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
				printf("��������˺Ŵ���\n");
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
			printf("������������ƻ����˺ţ�");
			scanf("%s",dp);
			printf("����������");
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
				printf("\t\t\n��   ��������˺Ŵ���\n");
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
	printf("������������");
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
				printf("\t\t�����û��Ѿ�����ע���,����������:");
				scanf("%s",a);
				break;
			}
			else
				p=p->next;
		}
		if(i==0)
			break;
	}
	printf("�������ջ���ַ��");
	scanf("%s",b); 
	printf("���������룺");
	scanf("%s",c);
	printf("������绰���룺");
	scanf("%s",d); 
	x=strlen(c);
	while(x<8)
	{
		printf("\t\t��   ��������С��8λ����ȫָ��Ϊ��\n");
		printf("��1�޸�,�����������޸�:");
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
		printf("Ϊ�˷����ֵǮ��������������п���");
		scanf("%s",ca);
		h=strlen(ca);
		while(h<15)
		{
			printf("\t\t��   �������п�����15λ�����������룺");
			scanf("%s",ca);
			h=strlen(ca); 
		}
		i=0; 
		printf("����������֧������");
		scanf("%s",mi1);
		printf("��ȷ������");
		scanf("%s",mi2);
		if(strcmp(mi1,mi2)!=0)
		{
			printf("\t\t��ע��ʧ��,�������벻ͬ");
			return 0;
		}
		fp=fopen("yue.txt","at");
		fprintf(fp,"%s %s %s\n",a,ca,mi1);
		fclose(fp);
	}
	else
	{
		printf("\t\t��ע��ʧ�ܣ���������ȷ���ջ���Ϣ��");
		return 0;
	}
	return LU; 	 
}
void Register()
{
	int y;
	char a;
	FILE *fp;
	shop sq;//���� 
	system("cls");
	printf("\n\n\n\t\t\t\t1.ע���û�\t\t\t2.�������\n");
	printf("\t\t\t\t0.������һ��");
	while(1)
	{
		printf("\t\t��  ��ѡ��Ҫ���е�ѡ�"); 
		scanf("%d",&y);
		if(y==1)//�û�ע�� 
		{
			link_user LU;
			LU=creatu(); 
			userwrite2(LU);
		}
		if(y==2)
		{
			printf("������������ƣ�");
			scanf("%s",sq.name);
			printf("��������̵绰��");
			scanf("%s",sq.phone);
			printf("��������̵�ַ��");
			scanf("%s",sq.address); 
			printf("������������룺");
			scanf("%s",sq.password);
			fp=fopen("shenqing.txt","at");
			if(fp==NULL)
			{
				printf("���������޷����ļ�");
				return; 
			}
			printf("�Ƿ񱣴棿Y/else");
			scanf("%*c%c",&a);
			if(a=='Y')
			{	
				fprintf(fp," %s %s %s %s \n",sq.name,sq.phone,sq.address,sq.password);
				fclose(fp);
				printf("\t\t��   ����ɹ����ȴ��ϼ����"); 
			}
			else
			{
				printf("\t\t��   �ѷ�������");
				fclose(fp); 
			}
		}
		if(y==0)
		{
			system("cls");
			printf("\t\tWELCOME\n��������������ϵͳ����ѡ��������Ĳ�����");
			printf("\n\n\t\t\t\t1.��½");
			printf("\t\t\t\t2.ע��\n"); 
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

