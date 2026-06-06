#include <ansi.h>
inherit NPC;
string do_special_fight();
void create()
{
        set_name("頂級金刀",({"blade man","man"}));
        set("long","魔龍塔守護者，由幻影系統copy。\n");
        set("gender","男性");
        set("combat_exp",13000000);
        set("long","魔龍塔守護者，由幻影系統copy。\n");
        set("sec_kee","tiger");
        set("title",HIW + "～幻影～" + NOR);
        set("attitude","heroism");
        set("max_s_kee",1000);
        set("family/family_name","金刀門");
        set("env/連擊","YES");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
        (: do_special_fight :),
        }));
        set("s_kee",1000);
        set("age",60);
        set("force",500000);
        set("max_gin",9000);
        set("max_kee",50000);
        set("max_sen",9000);
        set("clan_kill",1);
        set("bellicosity",2500);
        set("max_force",500000);
        set("force_factor",20);
        set("str",45);
        set("cor",45);
        set("mpower",1);
        set_skill("blade",120);
        set_skill("gold-blade",120);
        set_skill("fast-blade",120);
        set_skill("literate",120);
        set_skill("sixforce",120);
        set_skill("black-steps",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
        map_skill("blade","fast-blade");
        map_skill("parry","gold-blade");
        map_skill("force", "sixforce");
        map_skill("dodge", "black-steps");
        set_temp("apply/defense",100);
        set_temp("apply/armor",100);
        setup();
        carry_object("/daemon/class/blademan/obj/gold-blade")->wield();
        add_money("gold", 20);
}
void heart_beat()
{
object me,room,*target;
int i,j;
me=this_object();
room=environment(me);
target=me->query_enemy(room);
if(i=sizeof(target)) {
if(random(100) > 50)
{
if(random(9) >= 5)
{
message_vision(HIY + "頂級金刀把刀一晃，你為了閃避，冷不防的被打了一拳！\n" + NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-1500); }
   }
   else
   {
message_vision(HIC + "頂級金刀仰天一笑，瞬時內息穩固。\n" + NOR,me);
if(random(9) >= 5) {
me->receive_curing("kee",2000);
me->receive_heal("kee",2000);
}
    me->clear_condition();
   }
  }
}
  ::heart_beat();
  }
int accept_fight(object who)
{
 command("say 走開別煩我！\n");
return 0;
}
int accept_kill(object who)
{
 who=this_player();
 command("kill "+who->query("id"));
 command("cmd usekee "+who->query("id"));
 return 1;
}
string do_special_fight()
{

        if( query_skill_mapped("blade") == "fast-blade" ) {
            command("perform blade.fast-dest");
            map_skill("blade", "gold-blade");
        }
        else if( query_skill_mapped("blade") == "gold-blade" ) {
            command("perform blade.gold-dest");
            map_skill("blade", "fast-blade");
        }
        command("perform blade.gold-dest");
        return "";
}
int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 35)
       {
        message_vision(HIY + "
恭喜"HIW+me->query("name")+HIY"挑戰" + HIG + "『" + HIR + "第三十四層試煉ソ塔" + HIG + "』" + HIY + "通過！！

" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖" + HIG + "『" + HIY + "第三十五層試煉ソ塔" + HIG + "』" + HIW + "。
	" + NOR,me);
	me->set("quest/start_game",35);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
