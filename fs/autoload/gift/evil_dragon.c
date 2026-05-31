//2003 12.17ºô»E¼ú«~  by Guetenr
//¾i¦¨«¬°¨¤Ç ©Ò¦³¤H - mudu
/*¸gneverend ­×§ï«á¦p¤U
        1.°¨ªºcombat_exp ³Ì°ª­È¬°¤@¤d¸U, °ò¥»combat_exp¥Ñ¨â¦Ê¸U°_¸õ
        2.°¨§ðÀ»¤O, ¨¾¦u¤O­È³]©w¬°³Ì°ª80(set_temp)
        3.¼W¥[playerªºtemp­È³Ì°ª¬°60           */
/*¤´µM¤Ó°ª¡A¤§«eªº³]©w¥i¯à¬O¤ñ·Ó¤Ñ°¨¡A¦ý¶·ª`·N¡G
  ¤Ñ°¨«ù¦³ªÌ¬°¤M«È¡A¨äÂ¾·~¥»¨­´N¥iÃM­¼°¨¤Ç¡A
  ¬G¤Ñ°¨©Òµ¹ªºtemp­È¬O¤@¯ë¤M«È¯àÃMªº³Ì°ª¯Å°¨¦A+10
  ¦Óevil-dragon ©M sheep ªº«ù¦³ªÌ¥»¨­Â¾·~¨Ã¤£¯àÃM°¨
  µ¹¤©¥Ø«e³Ì°ª45ªºtemp¼W¥[­È¤Ó¹L¸Ø±i¡A
  ¤£¹L¦]¬° fun Ãø½m¡A¬Gµ¹¤©³Ì°ª15ªº¼W¥[­È(¸û¤Ñ°¨¦h5)
  ©Msheep¦P¨B­×¥¿¤§by frequency */

#include <ansi.h>
#include <mudlib.h>
inherit NPC;
inherit SSERVER;
mapping *action = ({
([ "action" :"$N"HIY"¥û©Ê¤jµo ,¾U§QªºÀs¤ö¦V$n¬½¬½ªº§ì¤F¹L¥h ,¦ü­n¼¹µõ$n"NOR"¡C",
             "dodge"      :  -70,
             "parry"      :  -65,
             "damage"     :  60,
             "damage_type":  "§ì¶Ë",
           ]),
([ "action" :"$N"HIY"¨³³t¼³¦Ü$n­±«e ,º¡¤Ñ¤ö¼v´Â$n²rÀ»¤U¥h ,$n·í³õÂA¦å­¸Âq"NOR"¡C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "§ì¶Ë",
            ]),
([ "action" :"$N"HIY"±N¥þ¨­¤O¶q¶°¤¤¦b§À¤Ú ,¹ï·Ç$n¨­¤W¬½¬½ªº±½¥h ,¦n¤£Åå¤H"NOR"¡C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  70,
             "damage_type":  "¤º¶Ë",
            ]),
([ "action" :"$N"HIY"´Â$n²r¼²¤F¹L¥h ,¤d¤ç­«ªº¨­Åé ,®µµÛ¸U§¡¤§¶Õ ,¥O¤H¾v«ü"NOR"¡C
",
             "dodge"      :  -40,
             "parry"      :  -75,
             "damage"     :  75,
             "damage_type":  "¼²¶Ë",
            ]),
([ "action":"$N"HIY"¤@Án¨g§q ,±q¤f¤¤¼Q¥X"HIR" ¯P¿V "HIY"±N$nªº¨­Åé¾ã­ÓÃl¸n¦í"NOR
"¡C",
             "dodge"      : 40,
             "parry"      :  -60,
             "damage"     : 72,
             "damage_type":  "ÄY­«¨`¶Ë",
           ]),
       });

void create() 
{
        set_name(HIB"¶Â"HIC"¦â"HIB"¤p"HIC"Às"NOR,({"evil dragon" , "dragon","evil"})); 
        set("long", "³o°¦¬O¶Ç»¡¤¤§ÙÆF¤§¤ý©Ò·f­¼ªº¦aº»¯«Às, Å¥»¡
                     ¦pªGÃM¥L, ¥i¥H¨ì¹FÅ]¬ÉºZ¦æµLªý¡C
                     "HIW"«b¼v­ßÀsªº·f­¼¤èªk¦p¤U :
                        ÃMÀs      ride <·f­¼ª«¤§id>
                        Áý­¹      feed Áý­¹ª«
                        §ð¼Ä      kill_enemy
                        ¤UÀs      dismount
                        ¦^´_¤º¤O  addforce
                        ¥sÀsÂ÷¶}  free_dragon\n"NOR);
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
        set("race","³¥Ã~");
        set("gender", "¶¯©Ê");
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
        set("limbs",({"ÀsÀY","Às¤ö","Às§À","Às­I","Às¸¡"}));
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

//¤U­±³o±Æµ{¦¡¥Ñ¥l³êÀsªºcall-dragon©Ò¶Çªº­È§@±µ¦¬, ¨Ã¥B­«·s³]©w
//°¨ªºmax_kee By Guetenr

void besummon(object who,object room)
{
    int funlv;
    object obj = this_object();
    funlv = who->query("functions/feed_horse/level");
    obj->set("functions/feed_horse/level",funlv); 
//ª½±µ³]©w°¨ªºfun lv,Åýµ{¦¡¤£­n¥Îfind_livingªº¤è¦¡¥h§äleader
    
    set("eff_kee",10000+funlv*200);         // ³]©w°¨ªºkee ³Ì¦h¬°30000
    set("kee",10000+funlv*200);
    set("eff_sen",10000+funlv*200);         // ³]©w°¨ªºsen ³Ì¦h¬°30000
    set("sen",10000+funlv*200);
    set("eff_gin",10000+funlv*200);         // ³]©w°¨ªºgin ³Ì¦h¬°30000
    set("gin",10000+funlv*200);
    set("combat_exp", 2000000+funlv*70000); //³]©w°¨ªºexp ³Ì¦h¬°¤@¤d¸U
    set_skill("parry",  50+funlv);
    set_skill("move",   50+funlv);
    set_skill("dodge",  50+funlv);
    set_skill("move",   50+funlv);
    set_skill("unarmed",50+funlv);

//¥H¤U¨C¤@­Ó§Þ¯à¥[Á`­È½Ð¤Å³]©w¶W¹L80¡Cby neverend
    set_temp("apply/armor",  30+funlv/2);
    set_temp("apply/defense",30+funlv/2);
    set_temp("apply/damage", 30+funlv/2);
    set_temp("apply/attack", 30+funlv/2);
//¥H¤W¨C­Ó§Þ¯à¥[Á`­È½Ð¤Å³]©w¶W¹L80¡Cby neverend

    if(funlv > 30 &&  funlv <= 70)
    {
          obj->set("title", HIW"¡y"HIB"¨¸"HIC"Às"HIB"ªì"HIC"¿ô"HIW"¡z"NOR);
          obj->set_name(HIB"¶Â"HIC"¦â"HIB"¤p"HIC"Às"NOR,({"evil dragon" , "dragon","evil"})); 
          set_name(HIC"¶Â¦â¤pÀs"NOR,({"evil dragon" , "dragon","evil"})); 
    }
    if(funlv >= 71 && funlv <= 99)
    {
          obj->set("title", HIY"¡y"HIR"¦å"HIY"Ä~"HIR"¬É"HIY"­­"HIR"¡z"NOR);
          set_name(HIB"¼vÀs"NOR,({"evil dragon" , "dragon","evil"})); 
    }
    if(funlv>=100)
        {
                obj->set("title", HIY"¡y"HIR"¦å"HIY"Ä~"HIR"¬É"HIY"­­"HIR"¡z"NOR);
                obj->set_name("[0;1mî[1mî[1;30m£[1m»[1;37m«[1mb[1;30m¼[1mv[1;37m­[1mß[1;30mÀ[1ms[0m"NOR,({"evil dragon" , "dragon","evil"})); 

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
           return notify_fail("§A·QÃM¤°»ò¡H\n");
        if(horse->query("horse")!=1)
           return notify_fail("³o¤£¬O°¨¤£¯àÃM­ò¡I\n"); 
        if(me->query_temp("marks/ascend"))
           return notify_fail("¦³ÃMÀs¤FÁÙ·QÃM¡A·Q³Q K §r¡C\n");
         if(me->query("id")!="mudu")
           return notify_fail("³o¤£¬O§Aªº®yÃM¡A¤£­nÀH«K¶ÃÃM³á!!\n");
        if(me->query_temp("is_riding"))
           return notify_fail("§A¤w¸gÃM¦bÀs¤W¤F¡C\n");
        message_vision("$N©Ô°_Å·Ã·¡A¶¶¶Õ¤@ÅDª½·fÀs­I¡I¥H»¨®ð¤Q¨¬ªº¤è¦¡µn©ó"+horse->query("name")+"ªº­I¤W¡I\n",me);
        command ("defend mudu");
        me->set_temp("is_riding", 1);

//¥H¤U³o³¡¥÷ªº³]©w¹L©ó±j¤j¡A¨C¤@­Ó§Þ¯à¥[Á`­È½Ð¤Å³]©w¶W¹L60¡Cby neverend
//¤w­×¥¿by frequency
        me->add_temp("apply/attack", 5+fun/10);
        me->add_temp("apply/parry",  5+fun/10);
        me->add_temp("apply/defense",5+fun/10);
        me->add_temp("apply/damage", 5+fun/10);
        me->add_temp("apply/armor",  5+fun/10);
        me->add_temp("apply/dodge",  5+fun/10);
        me->add_temp("apply/move",   5+fun/10);
        me->set_temp("ride_name",me->name()+"¥¿ÃMµÛ"+horse->name());
        set_heart_beat(1);
        return notify_fail("ÃM¤W"+horse->query("name")+"¤§«á¡A"+me->name()+"±þ®ð¥|Áa¡A¦³¦pîî¼v§ÙÆF­°¥@¡C\n");
}


int do_dismount() 
{
        int fun;
        object me,horse;
        horse = this_object();
        me = this_player();
        fun=horse->query("functions/feed_horse/level");
        if(!me->query_temp("is_riding"))
           return notify_fail("±z²{¦b¨Ã¨S¦³¾r©~Às¤W¡I¡I\n");
         if(me->query("id")!="mudu")
           return notify_fail("¥H±z·L¤£¨¬¹DªºªZ¥\\¡A¦ó¥H¹¥Às¦Ó­¼¤§??\n");
        me->delete_temp("is_riding");
        me->add_temp("apply/attack", -(5+fun/10));
        me->add_temp("apply/parry",  -(5+fun/10));
        me->add_temp("apply/damage", -(5+fun/10));
        me->add_temp("apply/armor",  -(5+fun/10));
        me->add_temp("apply/defense",-(5+fun/10));
        me->add_temp("apply/dodge",  -(5+fun/10));
        me->add_temp("apply/move",   -(5+fun/10));
        me->delete_temp("ride_name");
        message_vision(HIW"$N¤@­ÓÂ½¨­±q­ßÀs¸õ¤F¤U¨Ó¡I\n"NOR,me);
        set_heart_beat(1);
        return 1;
}

int do_full() {
        object me;
        me = this_player();
        if(!me->query_temp("is_riding"))
           return notify_fail("±z²{¦b¨Ã¨S¦³¾r©~Às¤W¡I¡I\n");
        if(me->query("max_force") == 0)
          return notify_fail("±z¨Ã¨S¦³¤º¤O, ­ßÀs¤]µLªk¬°§A®Ä¤O¡I\n");
        if(me->query("force") >= me->query("max_force"))
          return notify_fail("±zªº¤º¤O¥H¨ì·¥­­, ­ßÀs¬OµLªkÀ°±z¦A¼W¥[ªº¡I\n");
        me->add("force", me->query("max_force")/4);
          return notify_fail("±zªº¤º¤Oº¥º¥´£ª@·í¤¤¡I\n");
}

int do_freehorse()
{       
        int fun;
        object me;
        object horse = this_object();
        fun = horse->query("functions/feed_horse/level");
        me = find_living((string)this_object()->query_temp("my_boss"));
        message_vision(HIB"$N¦b$n"HIB"­I¤W¤@©ç¡A$n"HIB"¤@°}¨g§q¡A«K®i¯Í¦a´ÂµÛÅ]¬É¤ÑªÅ¯e­¸¦Ó¥h¡C\n"NOR,me,this_object());
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
          return notify_fail("»Õ¤U¨Ã¨S¦³³B©ó¦M«æªº¾Ô°«¤¤, ¦ó¥H©RÀs¾Ô°«??\n");
        if(!me->query_temp("is_riding"))
          return notify_fail("§A¨Ã¨S¦³¾r©óÀs¤W, «ç»ò¥i¥H¥sÀs¥h§ðÀ»©O??\n");
         if(me->query("id")!="mudu")
           return notify_fail("¥H±z·L¤£¨¬¹DªºªZ¥\\¡A¦ó¥H¹¥Às¦Ó­¼¤§??\n");
        message_vision(HIR "$N©Ô°Ê¤â¤¤Å·Ã·©¹, $n"HIR"À³Án½Ä¦V¼Ä¤H¡T\n" NOR,me,horse);
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
     return notify_fail("§A¤£¬O¨eªº¥D¤H¡A¶Ã¥s¤°»ò¡H\n");
   if ( !ob)
     return notify_fail("§A¨­¤W¨S¦³¤HÀY¥iÁý°¨¨à\n");
   if ( !ob->query("feed"))
     return notify_fail("³o¤£¬O°¨¨à³ßÅw¦YªºÀY¡I¡I\n");
   if ( horse->query_temp("havefeed"))
     return notify_fail("°¨¨àÁÙ¨S®ø¤Æ§¹²¦¡A§A·Q¼µ¦º¨e§r¡H\n");
   if ( me->is_fighting())
     return notify_fail("§A¦b¾Ô°«¤¤¡A¶ë¤£·Ç¤F¡D¡D\n");
   if (funlv == 100)
     return notify_fail("°¨¨à¤w¸gªÎ´þ´þ¤F¡A¤£¥Î¦AÁý¤F!!\n");
   
   message_vision("$N®³¤F¤HÀYÁý­¹°¨¨à¡A$n©BÂP©BÂP¦a¤@¤U¤l´N¦Y§¹¤F\n",me,horse);
   tell_object(me,horse->query("name")+"·PÄ±§ó¥[±j¤j¤F\n");
   horse->set_temp("havefeed",1);
   call_out("delfeed",180);
   destruct(ob);
   if(funlv<100) { function_improved("feed_horse",150+random(funlv/2)); }
  }
  else
  {
   tell_object(me,"¤£­n®³¤FªF¦è´N·Q©¹°¨¨à¼L¸Ì¶ë\n");
  }
  return 1;
}

void delfeed()
{
  object horse,me;
  horse = this_object();
  me = find_living((string)horse->query_temp("my_boss"));
  message_vision("$N¼¯óOµÛ¥D¤H¡A¦ü¥G¦b§i¶D$n¨e¤w¸g¨{¤l¾j¤F¡C\n",horse,me);
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
    return notify_fail("³o¬O§O¤Hªº°]²£, §A±þ¤£±o!\n");
}

int accept_kill(object me) {
    return notify_fail("³o¬O§O¤Hªº°]²£, §A±þ¤£±o!\n");
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
   message_vision("$N"RED"¼ÄÁn¨g§q¡AÁn­µ¦n¦ü¹p»ï!!¼Ä¤HÅ¥«á¹³µo¨g¦üªº¯«¸g¿ù¶Ã!!\n"NOR,mob);
   for( i = 0; i < sizeof(enemy); i++ ) 
     { 
      enemy[i]->start_busy(1);
     }
  }
  if(a>=31 && a<=60)
  {
  message_vision("$N"HIY"±i¶}¦å¬Ö¤j¤f¡A±q³ï¤¤¼Q¥X¥i©Èªº¶Â¦â¤õµK¡A±N¥|©P¤@¤ù¿N¦¨µJ¤g!!\n"NOR,mob);
  for( i = 0; i < sizeof(enemy); i++ ) 
     { 
      enemy[i]->add("kee",-fun*10);
      COMBAT_D->report_status(enemy[i],1);
      enemy[i]->start_busy(1);
     }
  }
  else if( a >=61 && a <=100)
  {
     message_vision("$N"HIC"¬Ý±¡ªp¤£¹ï¡A±N¥D¤H¸ü¨ìªÅ¤¤¡A¸Ñ°£¤F¤£§Qªº±¡ªp!!\n"NOR,mob);
     me->delete_busy();
     mob->delete_busy();               
  }
  else
  {  
     message_vision("$N"HIW"¬ðµM¶¡¦ü¥Gµo¤F¨g¡A´Â¼Ä¤H¤£Â_«r¥h¡A¥t¼Ä¤HµLªk©Û¬[!!\n"NOR,mob);
     for( b = 0 ; b < 5; b ++)           
     {
     //¶Ë®`³¡¥÷§Æ±æ¦A­°§C¦Üfun*8  §_«h§ðÀ»¤O·|¹L±j¨Ç¡Cby neverend
      message_vision("$N"HIR"¦b$n¨­¤W¯d¤U¤@¹D¹D§ì²ª!\n"NOR,mob,target);
      target->receive_damage("kee",fun*8,target);
      COMBAT_D->report_status(target,1);
     }
   }
   }
   ::heart_beat();
}

