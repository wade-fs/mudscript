// check_limit.c 查詢目前限制狀況 by ACKY

#include <limit.h>
#include <ansi.h>

int help( object me );

int main( object me, string arg )
{
        string check, CO, name;
        int ratio;
        object ob;

        if( !arg )
                ob = me;
        else {
                if( !wizardp(me) )
                        return notify_fail( "只有巫師才能查看玩家目前限制狀況。\n");
                ob = present( arg, environment(me) );
                if( !ob )       ob = find_player( arg );
                if( !ob )       return notify_fail("您要查看誰的限制狀況?\n");
        }

        switch( ratio = (MAX_KB-ob->query("net_count/count"))*100/MAX_KB )
        {
        case 90..100 : CO = HIG; break;
        case 80.. 89 : CO = GRN; break;
        case 60.. 79 : CO = HIY; break;
        case 40.. 59 : CO = YEL; break;
        case 20.. 39 : CO = HIR; break;
        case  0.. 19 : CO = RED+""; break;
        default      : CO = NOR;
        }

        if( ob == me )
                name = "您";
        else
                name = ob->query("name")+"("+ob->query("id")+")";

        check  = HIW + "\n目前"+name+"的限制情況如下 - \n\n" + NOR;
/*
        check+="目前流量限制停用中\n";
        check += sprintf(HIC + "\t尚可使用流量總數:%s %4d / %4d (%d%%) " + NOR + "單位: KB。\n", CO, MAX_KB-ob->query("net_count/count"), MAX_KB, ratio );
        check += sprintf(HIC + "\t距離下回補滿時間:" + NOR + " %s。\n\n", CHINESE_D->chinese_period( 86400-(time()-ob->query("net_count/date")) ) );
*/

        if(ob->query("cmds_cnts"))
        check += sprintf(HIY + "\t目前一分鐘指令上限:%d\t目前共下了%d個指令。\n" + NOR,
                    ob->query("cmds_cnts/max_cmds"),ob->query("cmds_cnts/cnt"));
        if(me->query("cmds_cnts/r1_time") && me->query("cmds_cnts/max_cmds") < 350)
          check+=sprintf("下次指令上限加一時間:%s\n",ctime(me->query("cmds_cnts/r1_time")));

        me -> start_more( check );
        return 1;
}

int help( object me )
{
        write(@HELP
        check_limit : 查詢目前的各種限制情況。

HELP
);
        return 1;
}

