#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //֧���ַ�������
#define MAX 6 //����MAX��ʾϵͳҪ��������������
int main()
{
    //ʹ���ַ��������ʾ�ַ���
   int i, j, temp;             //ѭ����������ʱ���ͱ���
   int count = 5;           //��ǰδ�����乬����������
   int choice;              //�ʵ۵�ѡ��1-4֮��
   int searchIndex = -1;    //������Ų��ҵ�Ԫ�ص��±�
   char emperorName[50];
   char tempName [20];      //���������ʱ�ַ���������
   char names[MAX][20] = {"����","����","��֪����","��ʩ","С���"};
   //�����ļ�������
   char levelNames[][10] = {"����","����","����","�ʹ���","��̫��"};
   //�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
   int levels[MAX] = {1,2,0,0,4,-1};
   //loves�����е�ÿ��Ԫ�ض�Ӧÿ�����ӵĺøжȣ���ʼ�����ÿ���˵ĺøжȶ�Ϊ100
   int loves[MAX]  = {100,100,100,100,100,-1};

   printf("\n*****************************************\n");
   printf("���Դ��룺�鿴��ǰ������״̬\n");
   printf("%-12s����\t�øж�\n","����");
   for(i = 0; i < count; i++)
   {
       printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
   }
   printf("*****************************************\n");


   printf("�����뵱ǰ�ǻ��Ļʵ�����: ");
   scanf("%s",emperorName);     //¼���ַ���ʱ������Ҫ&����
   printf("�ʵۡ�%s������,�������࣬�����˳��� \n",emperorName);
   printf("1.�ʵ���ּѡ���� \t\t(���ӹ���) \n");
   printf("2.���Ƴ��ң� \t\t(�޸�״̬����) \n");
   printf("3.�����乬�� \t\t (ɾ������) \n");
   printf("4.�����ټ�����ȥС������������¡� \n");
   printf("������ѡ��");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1://1.�ʵ���ּѡ���� \t\t(���ӹ���
        //1.����ǰ��Ҫ�ж�������û�пռ�
        //2.��������Ԫ�أ�names��loves��lovels��
        if(count < MAX)//�����ǰ����������С��ϵͳ���ֵ
        {
            //ִ����Ӳ���
            printf("���������������: ");
            scanf("%s",names[count]);
            //����count��Ԫ�ص�״̬��ʼ��
            levels[count] = 0;      //�����ʼΪ0
            loves[count] = 100;       //�øжȳ�ʼΪ100
            count++;                //�����Ԫ�غ󣬼ǵ����Ӽ�����
        }
        else
        {
            printf("���£�Ҫע�����壬���Ѿ�����Ϊ��!\n���ʧ��!\n");
        }

        break;
    case 2://���Ƴ��ң� \t\t(�޸�״̬����) \n
        //1.�ҵ�Ҫ�������ӵ��±�
        //2.�޸�������ӵ�״̬  �øж�+10�� ������һ���������߼��Ͳ�������
        //3.�޸��������ӵ�״̬  ������Ľ���ʺޣ��������Ӻøж�-10
        //��Ҫ�����bug: δ֧�����������ڵ�������������Բ�
        printf("���£���������췭�����������: ");
        scanf("%s",tempName);
        //�ַ����Ĳ���strcmp,��Ҫ����<string.h>
        //strcmp(tempName,"abc")  0-�����ַ�����ȣ� 1��ʾǰһ�����ں�һ���� -1��ʾ��һ������ǰһ��
        for(i = 0; i< count; i++)
        {
            if(strcmp(tempName, names[i]) == 0)     //�������������պõ��������е�ĳ������
            {
              loves[i] += 10;
              //����Ҫע�⣬���ܳ���5��(0-4֮��)
              levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;
            }
            else
            {
                loves[i] -= 10;
            }
        }
        break;
    case 3:
        printf("3.�����乬�� \t\t (ɾ������) \n");
        //1.����
        //2.����һ�����Ǹ�ǰ��һ��
        //3.����--
        //4.�޸��������ӵ�״̬���øж�-20   ******************ûд��
         printf("ֻҪ��Ҳ�ų����ƾʲô����Ҫ����� \n");
         printf("���£�������Ҫ�����乬������: \t");
         scanf("%s",tempName);
         //ѭ������
         for(i = 0; i < count; i++)
         {
             if(strcmp(tempName, names[i]) == 0)//�Ƚ��ַ����Ƿ����
             {
               //��¼����Ҫ���ҵ��±�
               searchIndex = i;
               break;
             }
         }
         if(-1 == searchIndex)//���searchIndex��ֵθ��ֵ-1����ʾû���ҵ�
         {
           printf("�龪һ�������˴����乬���óԳԸúȺȣ� \n");
         }
         else
         {
            for(i = searchIndex; i < count - 1; i++)
            {
                //names[i] = names[i + 1]; ��Ϊ���ַ������飬C�����в�֧�������ֱ�Ӹ�ֵ
                //������Ҫʹ��strcpy����ʵ������ĸ�ֵ,�����γ̻���ϸ���⣬����ֻ���˽���ʲô���ܼ���
                strcpy(names[i], names[i+1]);
                loves[i] = loves[i + 1];
                levels[i] = levels[i + 1];
            }
                count--;
         }
        break;
    case 4://�����ټ�����ȥС�������������
        //1.����
        //2.���Ӻøжȼ���
        //3.����ʹ���������ʫ�裬ʹ��������ֵķ�ʽ�����ֻʵ۵��Ĳ�
        printf("ֻҪ��Ҳ�ų����ƾʲô����Ҫ����� \n");
        break;
    default:
        printf("����Ϸ�ԣ��������ٴ�ȷ�ϣ� \n");
   }
    //����ӡ��������״̬ǰ���Լ������� ð������
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(levels[j] < levels[j + 1])
            {
                //��Ҫ��������������ͺøж�
                temp = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = temp;
                temp = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = temp;
                //ע���ַ����Ľ���
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j +1], tempName);
            }
        }
    }

    printf("\n*************************************************\n");
    printf("���Դ��룺�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n","����");
   for(i = 0; i < count; i++)
   {
       printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
   }



   return 0;
}
