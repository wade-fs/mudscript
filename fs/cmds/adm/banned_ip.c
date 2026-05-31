#include <ansi.h>
inherit F_CLEAN_UP;
#define ALLOW ({"add","del","check","help","quit"})
string change_local;
private void get_choice(string arg, object user);
private void get_value(string value, object user);
string WARNING=HIY"
        特別的注意!!
        如果你是第一次使用本系統或是對本系統並不熟悉
        請一定要進入(help)選項觀看使用方法，以免因為
        殊失而導致系統的不正常!!本系統目前並沒有對任
        何選項做任何的保護措施，所以請小心使用。
        \n"NOR;
string LOCAL="
        (add)   增加不允許\進入的ip
        (del)   刪除目前不允許\進入的ip，也就是讓該ip進入
        (check) 查看目前banned_ip有那一些
        (help)  觀看本系統說明檔
        (quit)  結束系統回到fs
        \n";
string DOHELP=HIG"
        本系統提供你增加，刪除，查詢目前有被禁用的ip，為了表達
        的方便，特別的使用了選單式的系統，讓操作更簡便，與以往
        不同的是，在設定上多了*這個萬用字元的使用。
        請注意，在這裡的設定與ok_ip的設定不同，請看下例:
        合法的宣告: 163.26.238.*
        不合法的宣告: 163.26.238*
        請將萬用字元加在.的後面，若沒有這樣的話可能造成判斷的錯
        誤。
        對本系統有任何的問題，請post在bss的board上，我一定會解
        決!!
        \n"NOR;
void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
        write(HIC"        你己經進入了banned_ip修改系統!!\n"NOR);
        write(WARNING);
        write(HIC"        本系統提供了下面的功\能!!\n"NOR);
        write(LOCAL);
        write("請輸入欲往之選項:\n");
        input_to( (: get_choice :), 0, this_player() );
        return 1;
}
private void get_choice(string arg, object user)
{
        int flag;

        if( member_array(arg, ALLOW) == -1 )
        {
        write("本系統並沒有提供你想要的服務，請重新輸入!!!\n");
        write(LOCAL);
        write("請輸入欲往之選項:\n");
        input_to( (: get_choice :), 0, this_player() );
        return ;
        }
        switch(arg)
        {
                case "check":
                        write("目前禁用的ip有:\n");
                        CBIP_D->ip_list();
                        flag=1;
                        break;
                case "quit":
                        write("多謝您使用本系統，下次再見!!!\n");
                        return ;
                        break;
                case "help":
                        write(DOHELP);
                        flag=1;
                        break;
                default:
                        change_local=arg;
                        flag=0;
                        break;
        }
        if(flag)
        {
        write(LOCAL);
        write("請輸入欲往之選項:\n");
        input_to( (: get_choice :), 0, this_player() );
        return ;
        }
        else
        {
        write("你目前要進入的項目是("+change_local+")!!\n");
        if(change_local=="add")
        {
                write("目前禁用的ip有:\n");
                CBIP_D->ip_list();
                write("請輸入要增加的ip:\n");
                input_to( (: get_value :), 0, this_player());
                return ;
        }
        else
        {
                write("目前禁用的ip有:\n");
                CBIP_D->ip_list();
                write("請輸入要刪除的ip:\n");
                input_to( (: get_value :), 0, this_player());
                return ;
        }
        }
        return ;
}
private void get_value(string arg, object user)
{

        if(!arg)
        {
        write("你並沒有作("+change_local+")這項動作!!!\n");
        }
        else
        {
                if(change_local=="add")
                {
                CBIP_D->add_ip(arg);
                }
                else
                {
                CBIP_D->del_ip(arg);
                }
        }
        write(LOCAL);
        write("請輸入欲往之選項:\n");
        input_to( (: get_choice :), 0, this_player() );
        return ;
}

