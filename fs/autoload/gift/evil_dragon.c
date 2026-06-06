//2003 12.17E~  by Guetenr
//i ҦH - mudu
/*gneverend קpU
        1.combat_exp ̰Ȭ@dU, combat_expѨʸU_
        2.O, uOȳ]w̰80(set_temp)
        3.W[playertempȳ̰60           */
/*MӰAe]wiOӤѰA`NG
  Ѱ̬MȡA¾~NiMǡA
  GѰҵtempȬO@MȯM̰ŰA+10
  evil-dragon M sheep ̥¾~äM
  ثḛ45tempW[ȤӹLرiA
  L] fun mAG̰15W[(Ѱh5)
  MsheepPBץby frequency */

#include <ansi.h>
#include <mudlib.h>
inherit NPC;
inherit SSERVER;
mapping *action = ({
([ "action" :"$N" + HIY + "ʤjo ,UQsV$nFLh ,n$n" + NOR + "C",
             "dodge"      :  -70,
             "parry"      :  -65,
             "damage"     :  60,
             "damage_type":  "",
           ]),
([ "action" :"$N" + HIY + "t$ne ,Ѥv$nrUh ,$nA學q" + NOR + "C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "",
            ]),
([ "action" :"$N" + HIY + "NOqb ,$nWh ,nH" + NOR + "C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "",
            ]),
([ "action" :"$N" + HIY + "$nrFLh ,d筫 ,۸U ,OHv" + NOR + "C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  75,
             "damage_type":  "",
            ]),
([ "action":"$N" + HIY + "@ngq ,qfQX" + HIR + " PV " + HIY + "N$nln" + NOR + "C",
             "dodge"      : 40,
             "parry"      :  -60,
             "damage"     : 72,
             "damage_type":  "Y`",
           ]),
       });

void create() 
{
        set_name(HIB + "" + HIC + "" + HIB + "p" + HIC + "s" + NOR,({"evil dragon" , "dragon","evil"})); 
        set("long", "oOǻFҷfas, ť
                     pGML, iHF]ɺZLC
                     " + HIW + "bvsfkpU :
                        Ms      ride <fid>
                              feed 
                              kill_enemy
                        Us      dismount
                        ^_O  addforce
                        ss}  free_dragon\n" + NOR);
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("horse",1);
        set("force",50000);
        set("max_force",50000);
        set("max_gin",10000);
        set("max_kee",10000);
        set("max_sen",10000);
        set("age", 30);
        set("race","~");
        set("gender", "");
        set("combat_exp", 2000000);
        set("attitude", "peaceful");
        set("score",10000000);
        set("gold", 100);
        set("exp", 1000000);
        set_skill("parry", 50);
        set_skill("move", 50);
        set_skill("dodge", 50);
        set_skill("move", 50);
        set_skill("unarmed", 50);
        set("limbs",({"sY","s","s","sI","s"}));
        set("verbs",({"bite","claw"}));
        set_temp("apply/armor",80);
        set_temp("apply/defense",80);
        set_temp("apply/damage",80);
        set_temp("apply/attack",100);
        setup();
        carry_object("/daemon/class/fighter/ywboots");
        carry_object("/daemon/class/fighter/ywhand");   
        carry_object("/daemon/class/fighter/ywgem");    
        carry_object("/daemon/class/fighter/ywsu");
        carry_object("/daemon/class/fighter/ywhelmet");
        carry_object("/daemon/class/fighter/ywleg");
        carry_object("/daemon/class/fighter/ywcloth");
 set("default_actions", (: call_other, __FILE__,"query_action" :));
         reset_action();
     set_heart_beat(1);

}
mapping query_action()

{
   return action[random(sizeof(action))];
}


void init() 
{
        add_action("do_ride","ride");
        add_action("do_dismount","dismount");
        add_action("do_full","addforce");
        add_action("do_freehorse", "free_dragon");
        add_action("do_test", "kill_enemy");
        add_action("do_feed", "feed");
}

//UoƵ{ѥlscall-dragonҶǪȧ@, åBs]w
//max_kee By Guetenr

void besummon(object who,object room)
{
    int funlv;
    object obj = this_object();
    funlv = who->query("functions/feed_horse/level");
    obj->set("functions/feed_horse/level",funlv); 
//]wfun lv,{nfind_living覡hleader
    
    set("eff_kee",10000+funlv*200);         // ]wkee ̦h30000
    set("kee",10000+funlv*200);
    set("eff_sen",10000+funlv*200);         // ]wsen ̦h30000
    set("sen",10000+funlv*200);
    set("eff_gin",10000+funlv*200);         // ]wgin ̦h30000
    set("gin",10000+funlv*200);
    set("combat_exp", 2000000+funlv*70000); //]wexp ̦h@dU
    set_skill("parry",  50+funlv);
    set_skill("move",   50+funlv);
    set_skill("dodge",  50+funlv);
    set_skill("move",   50+funlv);
    set_skill("unarmed",50+funlv);

//HUC@ӧޯ[`ȽФų]wWL80Cby neverend
    set_temp("apply/armor",  30+funlv/2);
    set_temp("apply/defense",30+funlv/2);
    set_temp("apply/damage", 30+funlv/2);
    set_temp("apply/attack", 30+funlv/2);
//HWCӧޯ[`ȽФų]wWL80Cby neverend

    if(funlv > 30 &&  funlv <= 70)
    {
          obj->set("title", HIW + "y" + HIB + "" + HIC + "s" + HIB + "" + HIC + "" + HIW + "z" + NOR);
          obj->set_name(HIB + "" + HIC + "" + HIB + "p" + HIC + "s" + NOR,({"evil dragon" , "dragon","evil"})); 
          set_name(HIC + "¦ps" + NOR,({"evil dragon" , "dragon","evil"})); 
    }
    if(funlv >= 71 && funlv <= 99)
    {
          obj->set("title", HIY + "y" + HIR + "" + HIY + "~" + HIR + "" + HIY + "" + HIR + "z" + NOR);
          set_name(HIB + "vs" + NOR,({"evil dragon" , "dragon","evil"})); 
    }
    if(funlv>=100)
        {
                obj->set("title", HIY + "y" + HIR + "" + HIY + "~" + HIR + "" + HIY + "" + HIR + "z" + NOR);
                obj->set_name("bvs" + NOR,({"evil dragon" , "dragon","evil"})); 

                command("wear all");
        }
}


int do_ride(string str) 
{
        int fun;
        object me,horse;
        me = this_player();
        horse = this_object();
        fun=horse->query("functions/feed_horse/level");
        if((str != "dragon") && (str != horse->query("id")))
           return notify_fail("AQMH\n");
        if(horse->query("horse")!=1)
           return notify_fail("oOMI\n"); 
        if(me->query_temp("marks/ascend"))
           return notify_fail("MsFٷQMAQQ K rC\n");
         if(me->query("id")!="mudu")
           return notify_fail("oOAyMAnHKM!!\n");
        if(me->query_temp("is_riding"))
           return notify_fail("AwgMbsWFC\n");
        message_vision("$N԰_ŷ÷Aդ@DfsIIHQ覡n"+horse->query("name")+"IWI\n",me);
        command ("defend mudu");
        me->set_temp("is_riding", 1);

//HUo]wLjjAC@ӧޯ[`ȽФų]wWL60Cby neverend
//wץby frequency
        me->add_temp("apply/attack", 5+fun/10);
        me->add_temp("apply/parry",  5+fun/10);
        me->add_temp("apply/defense",5+fun/10);
        me->add_temp("apply/damage", 5+fun/10);
        me->add_temp("apply/armor",  5+fun/10);
        me->add_temp("apply/dodge",  5+fun/10);
        me->add_temp("apply/move",   5+fun/10);
        me->set_temp("ride_name",me->name()+"M"+horse->name());
        set_heart_beat(1);
        return notify_fail("MW"+horse->query("name")+"A"+me->name()+"|aApvF@C\n");
}


int do_dismount() 
{
        int fun;
        object me,horse;
        horse = this_object();
        me = this_player();
        fun=horse->query("functions/feed_horse/level");
        if(!me->query_temp("is_riding"))
           return notify_fail("z{bèSr~sWII\n");
         if(me->query("id")!="mudu")
           return notify_fail("HzLDZ\\AHsӭ??\n");
        me->delete_temp("is_riding");
        me->add_temp("apply/attack", -(5+fun/10));
        me->add_temp("apply/parry",  -(5+fun/10));
        me->add_temp("apply/damage", -(5+fun/10));
        me->add_temp("apply/armor",  -(5+fun/10));
        me->add_temp("apply/defense",-(5+fun/10));
        me->add_temp("apply/dodge",  -(5+fun/10));
        me->add_temp("apply/move",   -(5+fun/10));
        me->delete_temp("ride_name");
        message_vision(HIW + "$N@½qsFUӡI\n" + NOR,me);
        set_heart_beat(1);
        return 1;
}

int do_full() {
        object me;
        me = this_player();
        if(!me->query_temp("is_riding"))
           return notify_fail("z{bèSr~sWII\n");
        if(me->query("max_force") == 0)
          return notify_fail("zèSO, s]LkAĤOI\n");
        if(me->query("force") >= me->query("max_force"))
          return notify_fail("zOH췥, sOLkzAW[I\n");
        me->add("force", me->query("max_force")/4);
          return notify_fail("zO@I\n");
}

int do_freehorse()
{       
        int fun;
        object me;
        object horse = this_object();
        fun = horse->query("functions/feed_horse/level");
        me = find_living((string)this_object()->query_temp("my_boss"));
        message_vision(HIB + "$Nb$n" + HIB + "IW@A$n" + HIB + "@}gqAKiͦaµ]ɤѪůeӥhC\n" + NOR,me,this_object());
        if(me->query_temp("is_riding"))
         {
          me->add_temp("apply/attack", -(5+fun/10));
          me->add_temp("apply/parry",  -(5+fun/10));
          me->add_temp("apply/damage", -(5+fun/10));
          me->add_temp("apply/armor",  -(5+fun/10));
          me->add_temp("apply/defense",-(5+fun/10));
          me->add_temp("apply/dodge",  -(5+fun/10));
          me->add_temp("apply/move",   -(5+fun/10));
         }
         me->delete_temp("ride_name");
         me->delete_temp("horse");
         me->delete_temp("is_riding");
         me->delete_temp("have_horse");
    destruct(this_object());
    return 1;
}

int do_test(string str)
{
        object me = this_player();
        object horse = this_object();
        object *all = me->query_enemy();
        int a;
        if(!me->is_fighting())
          return notify_fail("դUèSBM檺԰, HRs԰??\n");
        if(!me->query_temp("is_riding"))
          return notify_fail("AèSrsW, iHsshO??\n");
         if(me->query("id")!="mudu")
           return notify_fail("HzLDZ\\AHsӭ??\n");
        message_vision(HIR + "$N԰ʤ⤤ŷ÷, $n" + HIR + "nĦVĤHT\n" + NOR,me,horse);
        for( a = 0; a < sizeof(all); a++ ) 
        {
        horse->fight_ob(all[a]);
        all[a]->fight_ob(horse);
        }
return 1;
}

int do_feed(string arg)
{
  object me,horse,ob;
  int funlv;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  ob = present("head",me);
  funlv = me->query("functions/feed_horse/level");
  if (arg == "head")
  {
   if ( me != this_player())
     return notify_fail("AOeDHAåsH\n");
   if ( !ob)
     return notify_fail("AWSHYi\n");
   if ( !ob->query("feed"))
     return notify_fail("oOwYYII\n");
   if ( horse->query_temp("havefeed"))
     return notify_fail("٨SƧAAQerH\n");
   if ( me->is_fighting())
     return notify_fail("Ab԰A뤣ǤFDD\n");
   if (funlv == 100)
     return notify_fail("wgδFAΦAF!!\n");
   
   message_vision("$NFHYA$nBPBPa@UlNYF\n",me,horse);
   tell_object(me,horse->query("name")+"Pı[jjF\n");
   horse->set_temp("havefeed",1);
   call_out("delfeed",180);
   destruct(ob);
   if(funlv<100) { function_improved("feed_horse",150+random(funlv/2)); }
  }
  else
  {
   tell_object(me,"nFFNQL̶\n");
  }
  return 1;
}

void delfeed()
{
  object horse,me;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  message_vision("$NOۥDHAGbiD$newg{ljFC\n",horse,me);
  horse->delete_temp("havefeed");
}

void die()
{
        int fun;
        object me;
        object horse = this_object();
        fun = horse->query("functions/feed_horse/level");
        me = find_living((string)this_object()->query_temp("my_boss"));
        if(me->query_temp("is_riding"))
         {
          me->add_temp("apply/attack", -(5+fun/10));
          me->add_temp("apply/parry",  -(5+fun/10));
          me->add_temp("apply/damage", -(5+fun/10));
          me->add_temp("apply/armor",  -(5+fun/10));
          me->add_temp("apply/defense",-(5+fun/10));
          me->add_temp("apply/dodge",  -(5+fun/10));
          me->add_temp("apply/move",   -(5+fun/10));
        }
        me->delete_temp("ride_name");
        me->delete_temp("horse");
        me->delete_temp("is_riding");
        me->delete_temp("have_horse");
    destruct(this_object());
}

int accept_fight(object me) {
    return notify_fail("oOOH], Ao!\n");
}

int accept_kill(object me) {
    return notify_fail("oOOH], Ao!\n");
}
void heart_beat()
{
 object env,mob,*enemy,target,me;
 int i,fun;
 mob = this_object();
if(!strlen((string)this_object()->query_temp("my_boss"))) return ;
 me = find_living((string)this_object()->query_temp("my_boss"));
 fun = mob->query("functions/feed_horse/level");
 enemy=mob->query_enemy();
 env = environment(mob);

 if(fun >=70 && random(100)>70&&env=environment(enemy[i]))
 {
   int a = random(fun+20);
   int b;
   i=sizeof(enemy);
   target = enemy[random(i)];
   if( a < 30 )
   {
   message_vision("$N" + RED + "ngqAnnp!!ĤHťṳogg!!\n" + NOR,mob);
   for( i = 0; i < sizeof(enemy); i++ ) 
     { 
      enemy[i]->start_busy(1);
     }
  }
  if(a>=31 && a<=60)
  {
  message_vision("$N" + HIY + "i}֤jfAq襤QXiȪ¦KAN|P@NJg!!\n" + NOR,mob);
  for( i = 0; i < sizeof(enemy); i++ ) 
     { 
      enemy[i]->add("kee",-fun*10);
      COMBAT_D->report_status(enemy[i],1);
      enemy[i]->start_busy(1);
     }
  }
  else if( a >=61 && a <=100)
  {
     message_vision("$N" + HIC + "ݱpANDHŤAѰFQp!!\n" + NOR,mob);
     me->delete_busy();
     mob->delete_busy();               
  }
  else
  {  
     message_vision("$N" + HIW + "MGoFgA¼ĤH_rhAtĤHLk۬[!!\n" + NOR,mob);
     for( b = 0 ; b < 5; b ++)           
     {
     //ˮ`ƱACfun*8  _hO|LjǡCby neverend
      message_vision("$N" + HIR + "b$nWdU@DD첪!\n" + NOR,mob,target);
      target->receive_damage("kee",fun*8,target);
      COMBAT_D->report_status(target,1);
     }
   }
   }
   ::heart_beat();
}

