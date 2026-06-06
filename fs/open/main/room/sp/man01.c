inherit NPC;
#include <ansi.h>

void create()
{
        set_name("老人",({"old man","man"}));
        set("title",YEL"元神販售"NOR);
        set("age",110);
        set("long","
老人神情鬼怪的向你問說 : [ 來者啊 ! 吾乃幽冥界人～
　　　　　　　　　　　　　販賣元神維生～100兩黃金 / 1元神 ! 汝等欲之 ? ]
"HIY"ans yes (no)\n\n"NOR);
        set("inquiry",([
        "元神":"[ 吾乃販售人間元神者 , 元神乃死人之靈也 ] \n",
]));
        setup();
}

void init()
{
        add_action("do_ans","ans");
}

int do_ans(string arg)
{
object me,ob;
int a,b,c;
        me = this_player();
        ob = this_object();
        a = (int)me->query("bank/coin");
        b = (int)me->query_spi();
        c = (int)me->query("refine/common/soul");

        if(!arg)
                return 0;
        if( arg!="yes" && arg!="no")
                return notify_fail("
老人喃喃自語說：[ 阿彌陀佛.... ]\n");

        if( arg == "yes")
        {
                if( a >= 100000 )
                {
                        if( b > c )
                        {
                                (int)me->add("bank/coin",-100000);
                                (int)me->add("refine/common/soul",1);
                                tell_object(me,HIW"

天空突然閃出一道白光～直衝你的天靈蓋\ ! 你冷不勝防的顫抖了幾下 ～       
        
\n"NOR);
                        }
                        else
                        {
                                tell_object(me,"老人搖了搖頭，很顯然你的靈性已經無法在吸收任何元神了...\n");
                        }
                }
                else
                {
                        tell_object(me,"老人搖了搖頭，很顯然你銀行的存款不足100兩黃金...\n");
                }
        }

        tell_object(me,"老人緩緩唸道 : [ 阿彌陀佛 ... ]\n");    
return 1;
}
