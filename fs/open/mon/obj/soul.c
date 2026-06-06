#include <ansi.h>
inherit NPC;

string ice_spell();
string find_hole();

void create()
{
    set_name("蝶魂",({"die soul","soul","die"}));
    set("long","她是陸清風當年的愛人－上官蝶，因為某些事情而受罰被冰封為雕像。\n");
        set("no_kill",1);
        set("no_fight",1);
        set("no_conjure",1);
        set("inquiry",([
                "冰封秘咒" : (:ice_spell:),
                "洞穴" : (:find_hole:),
                "釋放" : "只要將當年我師父所用的法術再一次施展在奴家身上，奴家就可以重新獲得自由了...\n",
        ]));
    setup();
}

void init()
{
    object me = this_player();
        string gen;

    if(me->query_temp("icestorm/ice_spell")==1) {
        if(me->query("gender")=="男性") gen = "道長";
        else gen = "道姑";
    
        write(HIC + "蝶魂說道：多謝"+gen+"將我召喚出來...\n\n" + NOR);
                write(HIC + "雖然奴家的靈魂獲得解放，但軀殼還是被「冰封秘咒」給囚住了...\n\n" + NOR);
                write(HIC + "只希望"+gen+"好人作到底，將我給「釋放」出來...\n\n" + NOR);
                me->set_temp("icestorm/ice_spell",2);
    }
}

string ice_spell()
{
        object me = this_player();
        
        if(me->query_temp("icestorm/ice_spell")==2)
        {
                command("say 我只知道我師父將我冰封之後，便帶著一本書跳進了一座「洞穴」之內...");
                me->set_temp("icestorm/ice_spell",3);
                return "或許\那本書就是『冰封秘咒』吧...";
        }
}

string find_hole()
{
        object me = this_player();
        
        if(me->query_temp("icestorm/ice_spell")==3)
        {
                me->set_temp("icestorm/ice_spell",4);
                return "嗯...你試著轉動(turn)我的雕像看看...";
        }
}

