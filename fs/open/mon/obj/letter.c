inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("破損的信箋",({"break-letter","letter"}));
    set("long","
一封有點破損的信箋，你可以將它打開(apart)來看看...
        \n");
    set("unit","封");
    set("value",100);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_sac",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_auc",1);
    set_weight(20);
    setup();
}

void init()
{
        add_action("apa_letter","apart");
}

int apa_letter()
{
        object me = this_player();
        object ob = this_object();
        
        if(me->query_temp("icestorm/ice_spell")==7)
        {
                write("你拆開了信箋，拿出了裡面的信，緩緩的唸了出來...\n");
                write(HIW + "
你唸道：有緣人啊...貧道早知道會有這麼一天...\n
　　　　雖然貧道不認識你，但想必你應該是陸清風那小子的什麼人吧...\n
　　　　唉～其實貧道並不是故意要冰封小蝶的，只是她太過於痴心...\n
　　　　竟然不顧一切一心一意的要等到陸小子來接她下山...\n
　　　　貧道只好出此下策，免得她遭遇不幸，想來也真是太委屈她了...\n
　　　　只是...萬萬沒想到來不及將她復原，貧道就將在此長眠了...\n
　　　　於是只好提筆寫下此書，只望有人能再機緣中尋得此處，救出小蝶...\n
　　　　有緣人啊...既然你有能力尋得這個石穴，想來法力也是不弱...\n
　　　　你就好好的修習我所遺下的『冰封秘咒』，等到你有了一定的功\力...\n
　　　　便可以破冰救出受冰封之苦小蝶了...\n
　　　　　　　　　　　　　　　　　　　　　　　　　　　　靈韻師太絕筆...\n
" + NOR);
                me->delete_temp("icestorm/ice_spell");
                me->set("get_book",1);
                return 1;
        }
}

