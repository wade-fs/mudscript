#include <armor.h>
#include <command.h>
#include <ansi.h>
#include <combat.h>
#include <skill.h>
#define MASTER "xing"
inherit EQUIP;
inherit SSERVER;
object user;
int kar,cor;
void create()
{
        seteuid(getuid());
        set_name( HBBLU+HIY + "沉溺之冠" + NOR ,({"crown ring", "ring"}));
        set_weight(2500);
        set("no_auc",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_save",1);
        set("light_up",-1); 
        if( clonep() )
               set_default_object(__FILE__);
        else {
            set("long","天堂島的寶貝，擁有不可思議的力量.\n");
            set("unit", "件");
            set("value",50000);
            set("material","gold");
            set("no_sell", 1);         //不然就得多攔 action sell
            /*set("armor_type","finger"); 
            set("armor_prop/armor", 7);*/        }
            set("light",-1);
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wear","wear");
     add_action("do_give","give");
     add_action("do_remove","remove");
     add_action("do_move","gomove");
     add_action("do_hand","hand");
     add_action("do_recover","recover");
     add_action("do_call","callnpc");
     add_action("do_robot","norobot");
}
int do_wear(string str)
{

     if(!(str=="crown ring" || str=="ring" || str=="all")) return 0;
     ::wear();
     if( query("equipped") )
     {
        user = this_player();     // 取得使用者
        user->add_temp("apply/armor",200);
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="crown ring" || str=="ring" || str=="all")
     if( query("equipped") )
     {
        user->add_temp("apply/armor",-200);
        if(user->query_temp("apply/armor") < 0)
          user->set_temp("apply/armor",0);
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
   if(str=="crown ring" || str=="ring" || str=="all")
     if( query("equipped") )
     {
        user->add_temp("apply/armor",-200);
        if(user->query_temp("apply/armor") < 0)
          user->set_temp("apply/armor",0);
        set_heart_beat(0);
     }
}
int do_remove(string str)
{
   if(str=="crown ring" || str=="ring" || str=="all")
     if( query("equipped") )
     {
        user->add_temp("apply/armor",-200);
        if(user->query_temp("apply/armor") < 0)
          user->set_temp("apply/armor",0);
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
   if(str=="crown ring" || str=="ring" || str=="all")
     if( query("equipped") )
     {
        user->add_temp("apply/armor",-200);
        if(user->query_temp("apply/armor") < 0)
          user->set_temp("apply/armor",0);
        set_heart_beat(0);
     }
}
int do_move()
{
        object me=this_player();
        me->move("/open/gblade/room/g1-10");
        return 1;
}
int do_hand()
{
     object me=this_player();
     object *target;
     int i,j;

     if(!me->is_fighting())  return 0;
     target=me->query_enemy();
     i=sizeof(target);
     i=random(i);
     for(j=0;j<=7+random(3);j++)
       COMBAT_D->do_attack(me,target[i],me->query_temp("weapon"),2);
     return 1;
}
int do_recover()
{
     object me=this_player();

     me->set("eff_kee",me->query("max_kee"));
     me->set("eff_gin",me->query("max_gin"));
     me->set("eff_sen",me->query("max_sen"));
     me->set("sen",me->query("max_sen"));
     me->set("kee",me->query("max_kee"));
     me->set("gin",me->query("max_gin"));
     me->clear_condition();
     me->clear_condition("mogi");
     return 1;
}
int do_call()
{
    object npc;
    int i,j;

    if(!j=this_player()->query("env/npc_num")) j=1;
    if(j<1 || j>3) j=1;

    for(i=0;i<j;i++){
      npc=new("/open/ping/npc/train4.c");
      npc->set("combat_exp",((this_player()->query("combat_exp"))*3-10));
      npc->move(environment(this_player()));
    }
    return 1;
}

int do_robot()
{
    this_player()->delete_temp("WARNING");
    if(!this_player()->query("robot/ans")) return 1;
    this_player()->delete("robot");
    return 1;
}
    
void heart_beat()
{
  object *target;
  int i,j,k,l;
  if( !objectp(user) ){
    set_heart_beat(0);
    return;
  }
  if(user->query_busy() > 0) user->delete_busy();
  if( user->is_fighting() && query("equipped") )
  {
    if(1){
      i=user->query("max_kee",1);
      j=user->query("max_force",1);
      k=user->query("max_gin",1);
      l=user->query("max_sen",1);
      j=j*2;
      if(user->query("force") < j)
        user->add("force",j/2*99);
      user->set("kee",i);
      user->set("eff_kee",i);
      user->set("gin",k);
      user->set("eff_gin",k);
      user->set("sen",l);
      user->set("eff_sen",l);
      user->clear_condition();
      user->clear_condition("mogi");
      if(user->query("env/連擊")){
        target = user->query_enemy();
        for(i=0;i<sizeof(target);i++){
          if(!target[i]) continue;
          target[i]->start_busy(3);
        }
      }
    }
  }
  return;
}


int query_autoload()
{
     object me;
     string user_id;
     me=this_player();
     user_id=getuid(me);
     if(user_id!=MASTER && !wizardp(me) && userp(me))
      return 0;
     else
     {
      this_object()->set("armor_type","finger");
      this_object()->set("armor_prop/armor", 7);
      return 1;
     }
}
