//仙人召喚 by Guetenr

#include <ansi.h>
#include <combat.h>

inherit NPC;

#define bell_big 600
#define bell_small 400
#define INVLEVEL 50
#define MANACOST 100
#define INVCOST 50

int special_att ();

object room2;
void create()
{
    set_name("九天妖狐", ({ "nine-fox","fox" }) );
    set("long", "在妖界數一數二的強力妖怪，全身雪白，擁有極高的靈性\n" +
            "和法力。後來被老君收服。\n");
            
    set("attitude", "peaceful");
    set("attitude", "heroism");
    set("gender","男性");
    set("max_force",10000);  
    set("max_kee",10000);
    set("force_factor",30);
    set_skill("dodge",200);
    set("str", 30);
    set("cor", 30);
    set("cps", 25);
    set("int", 50);
    set("spi", 50);
    set ("chat_chance_combat",35);
    set ("chat_msg_combat", ({(: special_att :)}));
    setup();
}

void besummon(object who,object room)
{
    int i, bell,pp;
    object *enemy;
    object me = this_object ();
    room2=room;

    message_vision (MAG"一陣冷風吹過，一隻$N緩緩地現形。\n" NOR, me);
    pp=who->query("combat_exp");
    set("combat_exp",pp*3/2);
    if( pp > 500000 )   
        pp = 500000;
    set("max_kee",pp/100);
    set("kee",pp/100);
    
        bell = who->query ("bellicosity");
    if (bell > bell_small)
    {
        message_vision (HIB"$N冷笑道:就憑你?\n", me);
        kill_ob (who);
        set_leader (who);
        return;
    }

    enemy = who->query_enemy ();
    i = sizeof(enemy);
    while(i--) {
        enemy[i]->fight_ob(this_object());
        fight_ob(enemy[i]);

    }
    set_leader(who);
         who->add_temp ("invocation", INVCOST);
}

void init()
{
       
      set_heart_beat(1);
}

void heart_beat()
{
    object who = query_leader ();
    int akee= who->query("kee",1);
    int bkee= who->query("max_kee",1);
    if(akee<bkee)
    {
     who->set("kee",bkee);
    }
    if(!who)
    {
      call_out("leave",0);
      return;
    }
    if (!is_fighting() ) 
    {
       call_out("leave", 0);
       return;
    }
    if(room2!=environment(who)||!who->is_fighting()) 
    {
       call_out("leave",0);
       return;
    }

       :: heart_beat();
}

void leave()
{
  object who = query_leader ();
    if( environment() )
  message_vision (
          MAG"一陣冷風吹過，$N的身形再度隱入黑暗之中～～～\n" NOR, this_object ());
  if (who)
    who->add_temp ("invocation", -INVCOST);
  destruct(this_object());
}

void unconcious ()
{
  object who = query_leader ();
  if (who)
    who->add_temp ("invocation", -INVCOST);
  message_vision (HIG"$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());
}

int needlevel ()
{
  return INVLEVEL;
}

int manacost ()
{
  return MANACOST;
}

int invcost ()
{
  return INVCOST;
}

int special_att ()
{
  object me = this_object ();
  object *enemy = me->query_enemy (), victim;
  int i = sizeof (enemy);
  victim = enemy[random(i)];
message_vision (HIG"$N忽地一聲長嘯，一道異光自眼中電射而出～～～～～～\n\n"NOR, me);   
message_vision (HIC"$N頓時感到一陣迷惘，昏昏沈沈地不知所措。\n"NOR, victim);  
  victim->start_busy(3);  
  me->start_busy (1);
  return 1;
}

