inherit NPC;
#include <ansi.h>
void die_msg();
void create()
{
    set_name("吸血鬼",({"vampire"}) );
    set("gender", "男性");
    set("age",18);
    set("attitude", "peaceful");
    set("long", "陪段家弟子練習的學生 \n");
    set("kee",600);
    set("max_kee",600);
    set("combat_exp",800);
    set("corpse_gone",1);
     add_money("gold",1000);
    set_temp("die",(: die_msg :));
    setup();
}
void init()
{
    if(!this_player()) return;
    if(this_object()->query_temp("unconcious")) return ;
    if(environment(this_object()) != environment(this_player())) return ;
    if(userp(this_player()))
    call_out("do_act",2,this_player());
}
int do_act(object ppl)
{
    kill_ob(ppl);
    return 1;
}
void die_msg()
{
    message_vision(HIY + "$N發覺身上的傷勢嚴重，慘叫了一聲，忽然間變成了一隻蝙蝠，朝裡面飛去！\n" + NOR,this_object());
    return ;
}
