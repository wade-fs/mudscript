//女影門掌門(write by cyw)
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

void do_special()
  {
    object *enemy,target;
    int i;

        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target=enemy[random(i)];

                message_vision(
HIM"\n奈美念起忍術：「啊～～～凍體封念」\n"NOR,target);
                message_vision(
HIW"\n四周空氣急冷$N的力氣全部都消失了！！！\n"NOR,target);
                target->receive_wound("kee",random(50+100));
                target->start_busy(5);
                COMBAT_D->report_status(target);
}



void create()
{
        set_name("澄香奈美",({"Master Ma","master","ma"}));
        set("gender","女性");
        set("class","killer");
        set("title",HIM"女影門究極奧義流傳人"NOR);
        set("attitude","heroism");
        set("long","她是女影門未來的首領");
        set("age",21);
        set("str",30);
        set("cor",40);
        set("cps",30);
        set("per",60);
        set("int",55);
        set("con",30);
        set("spi",55);
        set("kar",50);
        set("combat_exp",1000000);
        set("gin",1500);
        set("kee",1500);
        set("sen",1500);
        set("max_gin",1500);
        set("max_kee",1500);
        set("max_sen",1500);
        set("atman",0);
        set("force",3000);
        set("mana",3000);
        set("max_atman",0);
        set("max_force",3000);
        set("max_mana",3000);
        set("force_factor",10);
        set_skill("unarmed",60);
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("force",100);
        set_skill("haoforce",100);
         set_skill("fole-ken",50);
        set_skill("sha-steps",100);
        set_skill("parry",100);
        set_skill("blade",100);
        set_skill("season-flower-blade",100);
          set_skill("spells",100);
        map_skill("force","haoforce");
         map_skill("unarmed","fole-ken");
        map_skill("parry","season-flower-blade");
        map_skill("dodge","sha-steps");
        map_skill("blade","season-flower-blade");
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (:do_special:)
        }));
        setup();
        set_heart_beat(1);
        carry_object("/open/japan/obj/super-cloth.c");
        carry_object("/open/japan/obj/super-blade.c");
}
int accept_fight(object who)
{ 
return notify_fail("澄香奈美說道:先師說過不能隨便施展本門絕學！\n");
}
int accept_kill(object who)
{  
object me;
me=this_object(); 
if( me->is_fighting()) 
return 1;
command("say 可惡那我只好破例施展本門武學了!小心了!");
command("wear cloth");
return 1;
}
void heart_beat()
{
  object i;
  i=this_object();
  if( i->query("kee") < 1000 && !(i->query_temp("weapon")) && i->is_fighting())
  {
  command("say 中原真是臥虎藏龍,真沒想到居然需要祭出鎮門寶刀!");
  command("wield blade");
  }
  if( !(i->is_fighting()) && (i->query_temp("weapon")))
  command("unwield blade");
  ::heart_beat();
}
void init(){
      if(this_player()->query_temp("blood")== 1){
      command("say 大膽狂徒竟敢殺了我教門人,~~~納命來吧!");
      command("wear cloth");
      kill_ob(this_player());}
}
void die(){
	object killer;
	killer = query_temp("last_damage_from");
        killer->set_temp("blood", 1);
        message_vision(HIR"$N狠狠地瞪著$n說:$n.....你.別得意....我...教..中人.....會為我..報...
........ .仇...的..........(斷氣)"NOR,this_object(),killer);
	::die();
}	
