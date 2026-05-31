
int help();

int main(object me, string str)
{
        string  flag, okip, *ip_list, *ips;
        int     i;

        if( !str ) {
                if(!me->query("ok_ip"))
                        write( "你還沒設 ok-ip.\n");
                else
                        write( "你的 ok-ip 現在設定為 :\n"+"  "+
                                (string)me->query("ok_ip")+"\n" );
                return 1;
        }

        if( (string)me->query("name") == "guest" )
                return notify_fail("你不能幫 guest 設 okip!!\n");

        if( sscanf(str,"-%s %s", flag, okip) != 2 )
                return help();

        if( me->query("ok_ip") )
                ip_list = explode( me->query("ok_ip"), ":" );
        else 
                ip_list = ({});

        if( okip == "now" )
                ips = ({ (string)me->query("ip") });
        else if( okip )
                ips = explode(okip,":");

        if( flag == "s" )
                ip_list = ips;
        else if( flag == "a" ) {
                for( i=0; i<sizeof(ips); i++ )
                        if( member_array(ips[i], ip_list) == -1 )
                                ip_list += ({ ips[i] });
        } else if( flag == "d" ) {
                for( i=0; i<sizeof(ips); i++ )
                        if( member_array(ips[i], ip_list) != -1 )
                                ip_list -= ({ ips[i] });
        } else return notify_fail("Wrong flag!\n");

        me->set("ok_ip", implode(ip_list,":"));

        write("OK-IP 現在設定為 :\n"+"  "+ me->query("ok_ip")+"\n");
        me->save();
        return 1;
}

int help()
{

        write(@C_HELP
指令格式﹕okip <-a | -d | -s> <IP:IP:...>

本指令可以讓您設定自己的 okip list。只有從這些 IP address 上
連過來的人才能使用這個人物。

參數說明﹕
    -a                          增加
    -d                          刪除
    -s                          重新設定

IP 格式可以為 140.113.23.32 或 140* 或 *23 或 cis* 或 *pc 等
。但請勿使用 "?"。若無給予任何參數﹐將會傳回現有的 okip list
。若 IP = now 則視為目前的 login IP。

當您不確定您的 ip name﹐或是當 ip name 不能正常作用時﹐ 請使
用 ip number 以避免錯誤。

範例﹕
    okip -a aaa.bbb.ccc.ddd     將 aaa.bbb.ccc.ddd 加入 okip 裡。
    okip -d aaa.bbb.ccc.ddd     將 aaa.bbb.ccc.ddd 自 okip 中刪除。
    okip -s aaa.bbb.ccc.ddd eee.fff.ggg.hhh
                                將原來的 aaa.bbb.ccc.ddd 替換為
                                eee.fff.ggg.hhh。

使用格式: okip [-a|-d|-s] [IP:IP:...]

    這指令可以用來設定你自己的 okip LIST﹐只有從這些 IP address 上連過
來的人才能使用這個人物 。

參數說明: a - 增加、d - 刪除、s - 重新設定。

    IP 格式可為 140.113.23.32 或 140* 或 *23 或 cis* 或 *pc 等。
但請勿使用"?"。若無給予任何參數將會傳回現有的 okip list。
若 IP = now 則視為目前的 login IP。

C_HELP
        );
}
