
#include <combat.h>
#include <ansi.h>
#include <mudlib.h>
#define MASTER "suzukiami"
inherit NPC;
inherit SSERVER;

int do_ascend(object me);
int do_descend();

void create()
{
  set_name(HIY"皮卡丘"NOR, ({ "pe-ca","ca" }) );
set("long",@LONG
你所看到的是神奇寶貝皮卡丘
牠是電擊型的神奇寶貝
絕招是十萬伏特和快速移動
要不騎的話，請打un_invocation
LONG);
  set("unit","隻");
  set("value","100");
  set("race", "野獸");
  set("gender","雄性");
  set("combat_exp",10000000);
  set("no_exp",1);
  set("age",24710);
  set("cor",40);
  set("str",20);
  set("kee",100000);
  set("max_kee",100000);
  set("sen",70000);
  set("max_sen",70000);
  set("gin",45000);
  set("max_gin",45000);
  set("force",32000);
  set("max_force",32000);
  set("bellicosity",1000);
  set("attitude","friendly");
  set_temp("apply/armor",100);
  set_temp("apply/damage",80);
  set("verbs",({"bite","claw"}));
  set("limbs", ({ "龍首", "龍爪", "龍身" , "龍腿" , "龍尾" }) );
  set("force_factor",25);
  set_skill("dodge",700);
  set_skill("parry",400);
  set_skill("unarmed",500);

  setup();

}


void init()
{
add_action("do_descend","un_invocation");
}

int do_ascend(object me)
{
        string name;
        if(!me) me=this_player();
        if(!me) return 0;
        if(!userp(me)) return 0;
        name=geteuid(me);
        if (name != MASTER && !wizardp(me) && userp(me))
           return notify_fail("你不是這座騎的主人("+MASTER+")無法騎他!!!\n");
        if ( me->query_temp("marks/ascend") )
               return notify_fail("你無法騎在別人的座騎身上呀。\n");
message_vision(HIY+"$N"+HIY+"大聲叫道:上吧!"+this_object()->query("name")+HIY+",
一道閃光從神奇寶貝球裡出現,
"+this_object()->query("name")+HIY+"出現在$N"HIY"眼前!!\n"NOR,me);
        me->set_temp("marks/ascend",1);
        me->add_temp("apply/dodge",30);
        me->add_temp("apply/parry",30);
        me->add_temp("apply/unarmed",30);
        me->add_temp("apply/attack", 30);
        me->add_temp("apply/defense",30);
        me->add_temp("apply/damage",30);
        me->add_temp("apply/armor", 30);
        this_object()->set_leader(me);
        this_object()->set("master",me);
        set_heart_beat(1);
        if(!query_heart_beat()) tell_object(me,"心跳啟動失敗!!\n");
        me->add_temp("ride_name",HIW"(正騎著"NOR+this_object()->name()+HIW")"NOR);
        return 1;
}

int do_descend()
{
        object me;
        string *name;

        me=query("master");
        if(me){
        if(geteuid(this_player())!=MASTER && !wizardp(this_player())){
          if(present(geteuid(me),environment(this_object()))){
            message_vision("$N說道:竟敢命令我的神奇寶貝, 去死吧!!!\n",me);
           present(geteuid(me),environment(this_object()))->kill_ob(this_player());
          }
          this_object()->fight_ob(this_player());
          return 1;
        }
        if ( !me->query_temp("marks/ascend") )
                return notify_fail("你沒在座騎上耶。\n");
message_vision(HIG"$N"HIG"向"+this_object()->query("name")+HIG"丟出了神奇寶貝球,
"+this_object()->query("name")+HIG"化成一道閃光消失在寶貝球裡!!\n"NOR,me);
        me->delete_temp("marks/ascend");
        me->delete_temp("ride_name");
        if(me->query_temp("apply")){
        me->add_temp("apply/dodge",-30);
        me->add_temp("apply/parry",-30);
        me->add_temp("apply/unarmed",-30);
        me->add_temp("apply/attack", -30);
        me->add_temp("apply/defense",-30);
        me->add_temp("apply/damage",-30);
        me->add_temp("apply/armor", -30);
        }
//        move(environment(me));
        set_heart_beat(0);
        tell_object(me,sprintf("
%s對你說道：我已經功\成身退，先回家睡覺囉!!!\n",this_object()->name()));
        }
        destruct(this_object());

        return 1;
}

void heart_beat()
{
  object enemy,who,user;
  int i,dodge;
  user=query("master");
  if(!user)
  {
    set_heart_beat(0);
    destruct(this_object());
    return ;
  }
  if(!living(user) || user->is_ghost())
  {
    die();
    return ;
  }
  if(!present(geteuid(user),environment(this_object())) && environment(user))
  {
    message_vision("$N"HIY"化成一道黃光，往天際飛去!!!\n"NOR,this_object());
    this_object()->move(environment(user));
    message_vision(HIY"一道黃光由天空降下，$N"HIY"出現在眾人眼前!!\n"NOR,this_object());
  }

 /* if( user->is_fighting() )
  {
    enemy=offensive_target(user);
    if(!enemy) return ;
    if(!present(enemy->query("id"),environment(this_object()))) return ;
    if( random(10) > 2 )
    {
      if(random(10) > 5)
      {
message_vision(HIW+"$n使出了十萬伏特攻擊向$N射了過去!!\n"+NOR,enemy,this_object());
      message_vision(HIC+"$N閃躲不及 ,被燒得的全身焦黑。\n"+NOR,enemy);
      enemy->receive_damage("kee", 500);
      enemy->start_busy(random(2));
      COMBAT_D->report_status(enemy);

      }else{
message_vision(HIW+"$n使出了十萬伏特攻擊向$N射了過去!!\n"+NOR,enemy,this_object());
      message_vision(HIC+"只見$N飛身側閃 ,輕輕避開疾光的攻擊...\n"+NOR,enemy);

     }
    }
  }*/
        return ::heart_beat();
}
void die()
{
        do_descend();
        return;
}
int accept_fight(object me) {
        return notify_fail("這是別人的財產, 你殺不得!\n");
}

int accept_kill(object me) {
        return notify_fail("這是別人的財產, 你殺不得!\n");
}


