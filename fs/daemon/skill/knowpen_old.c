/* ­×§ï by kalin 91-12-21
1.­ì¥»ªºªþ¥\¶Ë®`¤O³£¬°   int dam=victim->query("max_kee")/5;ªº¼gªk¡A
  §ï¬°¤£°Ñ·Ómob's kee ¥u°Ñ·Ó¦Û¨­µ¥¯Å¡C
2.¶}©ñ¾§´L,¤]°Ñ·Ó¥´¦ºfire king»P§_,¦ý¬O³o¨âÂI¥u¬O¼W¥[knowpen¥\¯à¡C
*/

#include <combat.h>
#include <ansi.h>
inherit SKILL;

void special_attact1(object me, object victim, object weapon, int damage);
void special_attact2(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object weapon, int damage);
void sp_att2(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object weapon, int damage);
void plan_king1(object me, object victim, object weapon, int damage);
void plan_king2(object me, object victim, object weapon, int damage);
void plan_king3(object me, object victim, object weapon, int damage);
void plan_king4(object me, object victim, object weapon, int damage);
mapping *action = ({
      ([
        "action"     :
"$N¤â¤¤$w¤@Â½¡M¤@©Û"HIW"¡y"NOR"¦æ¶³¬y"HIB"¤ô"HIW"¡z"NOR"¤â¸Ìªº$w¦p¤@±øªøÀs¬yÂà¡M©¹$n$l¨ë¥h",
        "dodge"      :               -10,
        "parry"      :               -10,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¨­§Î¬yÂà¡M³s½ò¤C¨B¡M¤â¤¤$w¤@©Û"HIW"¡y"HIG"¤C¨B¦¨"HIC"¸Ö"HIW"¡z"NOR"©¹$nÂI¥h",
        "dodge"      :                0,
        "parry"      :                0,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¤â¤¤$w·n®Ì¡M¨Bªk·L¹y¡M°¿¦a¤@©Û"HIW"¡y"HIW"§â"HIR"°s"NOR"°Ý¤Ñ"HIW"¡z"NOR"±N$w´§¥X¡M³s¥X¤T¤U©¹$nÂI¥h",
        "dodge"      :                -10,
        "parry"      :                10,
        "damage"     :                100,
        "force"      :                200,
        "damage_type":  "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N±N¤â¸Ìªº$w°ª°ªÁ|°_¡M©¿¦a¤â¤¤$w«æÅÜ©Û¼Æ¡M¤@©Û"HIW"¡y"HIY"µâ"HIM"¶éºÉ¿³"HIW"¡z"NOR"³sºø¤£µ´ªº©¹$n«æÂI",
        "dodge"      :                -20,
        "parry"      :                20,
        "damage"     :                100,
        "force"      :                200,
        "damage_type": "¨ë¶Ë",
      ]),
///////////////////////// Below Add By AceLan ////////////////////////////////
      ([
        "action"     :
"$N©¿µM¬n¬n±×±×ªº¨«¤F¨â¨B, ¨Ï¥X¤@©Û"HIW"¡y"HIR"©í¨B±×¦æ"HIW"¡z"NOR",´Â$n$l§ð¥h",
        "dodge"      :                -30,
        "parry"      :                30,
        "damage"     :                150,
        "force"      :                250,
        "damage_type": "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¬Ý·Ç¤F$n¨Ó¶Õ, ¨Ï¥X¤@©Û"HIW"¡y"NOR"ªïªù"HIB"ÅK"HIR"®°"HIW"¡z"NOR", ÃtÅxªºÁÙ¤F¤@À»",
        "dodge"      :                -30,
        "parry"      :                20,
        "damage"     :                150,
        "force"      :                250,
		"post_action":  (: plan_king4 :),
        "damage_type": "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¤j³Ü¤@Án, ¨­§Î«æÂà, ¨Ï¥X¾§ªùªºµ´©Û"HIW"¡y"HIB"Â½"HIR"ªá"HIY"»R"HIG"³S"HIW"¡z"NOR", ¤â¸Ì$w¦p«BÂI¯ë´Â$nÅx¸¨",
        "dodge"      :                -50,
        "parry"      :                40,
        "damage"     :                200,
		"post_action":  (: plan_king1 :),
        "force"      :                300,
        "damage_type": "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¾®»E¤º¤O, ¨­®ÇÀþ®É¨í°_±j­·, ³o¥¿¬O¾§ªùªº"HIW"¡y"HIB"­·"NOR"±½"HIR"±öªá"HIW"¡z"NOR", ¥u¨£$Nªº¨­¼vº¡¤Ñ­¸»R",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                200,
        "force"      :                300,
		"post_action":  (: plan_king2 :),
        "damage_type": "¨ë¶Ë",
      ]),
      ([
        "action"     :
"$N¨Ï¥X¤@©Û"HIW"¡y"HIB"»í¬P"HIM"ÂI"NOR"¤æ"HIW"¡z"NOR", ¥u¨£$N¤â¤¤$w©¿§Ö©¿ºC©¿¥ª©¿¥k¦a´Â$n¨­¤W«æÂI",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                250,
        "force"      :                 300,
		"post_action":  (: plan_king3 :),
        "damage_type": "¨ë¶Ë",
      ]),
           ([        "action":
"$NºCºC±N¯u®ð¹B¦æ¥þ¨­±a°Ê¥|©P®ð¬y¡A½w½w¦¬°_$w¡A·Ç³Æ¨Ï¥X¾§ªùÂí±Ðµ´¦¡¤§¤@\n"
"$Nªº¯u®ð¬ðµMºCºC®ø¥¢¡A´x¤O¶¶®É­°¦Ü¤T¤À¡A$n¥u¦³ÂI©Û¬[¤£¦í¡C",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att2 :),
              "damage_type":"·ï¶Ë"
             ]),
           ([         "action":
"$N±N´¤$w´«¦¨®³¼C¤§ºA¡A©¿¦a¤â¤¤¤Û¤Æ¦¨¼C¡A·Ç³Æ¨Ï¥X¾§±ÐÂí±Ðµ´¦¡¤§¤@\n"
"$N¦]µLªk´x´¤¦í»¤§x±þ·À¥|¶µ¼C·N¡A$n¦ü¥G¦³ÂI¬Ý¬ï¯}©Û¤§ªk¡C",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att3 :),
              "damage_type":"³Î¶Ë"
            ]),
      ([
        "action"     :
"$N¨­§Î«æÂà, ¬ðµM­âªÅÅD°_, ¤â¤¤$w¥ªÂ½¥kÂ½, ´Â$n¨­¤W«ü«üÂIÂI, «æÂI¦Ó¦Ü,
³o¤@©Û¥¿¬O¾§ªùªºµ´©Û"HIW"¡y"NOR"Âà"HIB"Às"HIG"°j"HIR"¤é"HIW"¡z"NOR,
        "dodge"      :                50,
        "parry"      :                30,
        "damage"     :                250,
        "force"      :                300,
        "damage_type": "¨ë¶Ë",
        "post_action": (: special_attact1 :),
      ]),
      ([
        "action"     :
"$N¨­§Î¬ðµM©Þ°ª¼Æ¤V, ¨Ï¥X¤@©Û"HIW"¡y"HIB"¶³"HIR"¶}"HIY"Às"HIB"ÄË"HIW"¡z"NOR", ¤â¤¤$w±qªÅ¤¤ÄÆµM¤U¹º,
¥u¨£¤@¹DµL§Î«l®ð, ®µµÛ¨g­·´ÂµÛ$n¿E®g¦Ó¦Ü",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "¨ë¶Ë",
        "post_action": (: special_attact2 :),
      ]),
      ([
        "action"     :
"$N¬ðµM¥þ¨­¥Rº¡ºñ¥ú¡A¨â²´¹q®g¥X­¢¤Hªº´H®ð¡A¨Ï¥X¾§ªù¦Ü°ªµ§ªk"HIW"¡y"HIB"ÆF"HIR"Às"HIY"µ§"HIB"®Ñ"HIW"¡z"NOR",
¥u¨£¤@¹D«l®ð®µµÛ¸U¤V¥ú¨~¤w±N$n¥þ¨­Å¢¸n¦í¤F",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "¨ë¶Ë",
        "post_action": (: sp_att1 :),
      ]),

});

void special_attact1(object me, object victim, object weapon, int dam)
{
   int i;
   int time=me->query("combat_exp")/1000000;
   dam=this_player()->query_skill("knowpen")*3;
   if(80>random(100))
   {
      if(!this_player()->query("plan-quest/ko-fire-king"))
	  {
      message_vision(HIB
"\n$N¤â¤¤"HIG+ weapon->query("name")+HIY"¹q¥ú¤õ¥Û"HIB"¯ë³s³sÅ¸°Ê, ¦Û$n"HIR"ÆF¥x¥Þ"HIB"¤@¸ô¶¶¶Õ¦Ó¤U, \n", me, victim);
      message_vision(
"¨Ïªº¬O¾§ªùªº"HIW"¦æ¶³¬y¤ôµ§ªk"HIB"¤¤³Ì­â¼Fªºµ´©Û, ¦b$n·þ¯ßªº¨C¤@¥Þ¹D³£ÂI¤W¤F¤@¤U¡C\n"NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
      }
      else
      {
        for(i=0;i<time;i++)
        {
   	      {
      message_vision(HIB
"\n$N¤â¤¤"HIG+ weapon->query("name")+HIY"¹q¥ú¤õ¥Û"HIB"¯ë³s³sÅ¸°Ê, ¦Û$n"HIR"ÆF¥x¥Þ"HIB"¤@¸ô¶¶¶Õ¦Ó¤U, \n", me, victim);
      message_vision(
"¨Ïªº¬O¾§ªùªº"HIW"¦æ¶³¬y¤ôµ§ªk"HIB"¤¤³Ì­â¼Fªºµ´©Û, ¦b$n·þ¯ßªº¨C¤@¥Þ¹D³£ÂI¤W¤F¤@¤U¡C\n"NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
           }
        }
	  }
   }
   else
   {
      message_vision(HIB
"\n$N¤â¤¤"HIW+ weapon->query("name")+HIB"¹q¥ú¤õ¥Û¯ë³s³sÅ¸°Ê, ¦Û$nÆF¥x¥Þ¤@¸ô¶¶¶Õ¦Ó¤U, \n"NOR, me, victim);
      message_vision(HIW
"¤£¹L$n¨­§Î§ó§Ö, ¥©§®ªºÁ×¹L¤F$Nªº³o­P©Rªº¤@À»\n"NOR, me, victim);
   }
}

void special_attact2(object me, object victim, object weapon, int dam)
{
   dam=this_player()->query_skill("force");
   if(80>random(100))
   {
      message_vision(HIB
"\n$N¨Ï¥X¬Ý®a¥»»â, ¹y®É¨g­·¤j§@, ¤â¤¤"HIW+ weapon->query("name")+HIB"¤Û¤Æ¥X°}°}­è®ð, \n", me, victim);
      message_vision(
"©¿¥ª©¿¥k, ¦üºC¹ê§Ö, ¦ü»´¹ê­«¦a´Â$n¨g¼A¦Ó¨Ó¡C\n"NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
   }
   else
   {
      message_vision(HIB
"\n$N¨Ï¥X¬Ý®a¥»»â, ¹y®É¨g­·¤j§@, ¤â¤¤"HIW+ weapon->query("name")+HIB"¤Û¤Æ¥X°}°}­è®ð, \n", me, victim);
      message_vision(
"©¿¥ª©¿¥k, ¦üºC¹ê§Ö, ¦ü»´¹ê­«¦a´Â$n¨g¼A¦Ó¨Ó¡C\n"NOR, me, victim);
      message_vision(HIW
"¤£¹L$n¨­§Î§ó§Ö, ¥©§®ªºÁ×¹L¤F$Nªº³o­P©Rªº¤@À»\n"NOR, me, victim);
   }
}

// valid_learn ¥u¬OÀË¬d¬O§_¥i¥H¾Ç, ¤£¯à¦b¦¹¥[ skill
int valid_learn(object me)
{
   if ((int)me->query_skill("literate")*2<(int)me->query_skill("knowpen"))
      return notify_fail("§AªºÅª®ÑÃÑ¦rµ{«×¤£°÷¡M¤£¯à»â®©¨ä¤¤ªº¹D²z¡C\n");
   return 1;
}

void sp_att1(object me, object victim, object weapon, int dam)
{
   if( 80>random(100))
   {
      if( present("ten pen", me))
      {
         dam=this_player()->query_cor()*25;
         message_vision(
"\n"HIY"$N¤f¸ÌÀq°á¡G"HIM"¡yµ§¾W¬yÂà¡A¹MÅé´H¥ú¡A§N»a¤§¤ë¡A­á¤Æ¦¨¨~¡z"NOR"\n"
""HIY"$N¼ç¹B¸Ö©ö¤ßªk¡A¸}½ñ¥VÁ÷¦B³·¨Bªk¡A¤â¸ÌÆFÀs¤Ñµ§¹y®Éµo¥X°}°}­è®ð¡C"NOR"\n"
""HIY"¥u¨£¥|©PªÅ®ðµ²¦¨°}°}´HÁ÷¡A´Â$n¿E®g¦Ó¦Ü¡A®g¬ï¤F$nªºÅ@Åé¯u®ð¡A³y¦¨­«³Ð"NOR"\n",me,victim);
      }
      else
      {
         dam=this_player()->query_cor()*20;
         message_vision(HIW"$NÀH·N´§¼»¤â¤¤"HIG+ weapon->query("name")+HIW"¡A¥u¨£°}°}­è®ð´Â$n¿E®g¦Ó¥X\n"NOR,me,victim);
      }
       victim->receive_damage("kee", dam);
       COMBAT_D->report_status(victim, 1);
       me->add("force",-100);
   }
}

void sp_att2(object me, object victim, object weapon, int damage)
{
   int i;
   int time=me->query("combat_exp")/500000;
   if(80>random(100))
   {
      message_vision(
"\n\n"HIW"$N¦A½w½w±N¯u®ð¹BÂà¤J¥ô·þ¤G¯ß¡A¶¶®É¯u®ð¥R¬Õ©ó¥þ¨­¤§¤¤¡A¨Ï¥X¾§ªùÂí±Ð¯µ©Û"NOR"\n"
""HIW"               ¡y¡ã¾§¡ã±Ð¡ã·¥¡ã©Û¡ã"HIC"§g"HIW"¡ã"HIC"¤l"HIW"¡ã"HIC"­·"HIW"¡ã¡z"NOR"\n"
""HIW"$N¯u®ðÀH´x¦Ó¥h¡A¨Ã±a°Ê¥|©P®ð¬yÀ»¦V$n¡A$n¦p¥¢½u¤§­·ºå¨ü³Ð­¸°_¡C"NOR"\n\n",me,victim);
   if(!this_player()->query("plan-quest/ko-fire-king"))
   {
      for(i=0;i<time;i++)
      {
         victim->receive_damage("kee", 75);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-30);
      }
   }
   else
   {
	     for(i=0;i<time;i++)
         {
         victim->receive_damage("kee", 100);
         message_vision(HIR"$N¨ú¥X½Ñ¸¯¤Õ©ú©Ò³Ð¤§³s©¸¡A¦V$nµ´µo¦Ó¥X¡I\n"NOR,this_player(),victim);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-30);
         }
   }
   }

}
void sp_att3(object me, object victim, object weapon, int damage)
{
           int dam=this_player()->query("bellicosity")/5;
           if( dam > 5000) dam= 500;
           if( dam < 50) dam= 50;
   if(80>random(100))
   {
      int i;
      for(i=1;i<=4;i++)
      {
         message_vision(HIW"§A´¤°_¤â¤¤¤§½Ñ»ñ¼Cµ§¡A¥Hµ§¥N¼C¡A¶¶®ÉÂI¯}µ´¦¡ºë§®¤§³B¡A¤Q¤À¬yºZªº¨Ï¥X¼C©Û¡I\n"NOR,me,victim);
         switch(i)
         {
            case 1:
                message_vision(sprintf(HIW"$N¨Ï¥X¡y"HIC"¼C¡ã¼v¡ã»¤¡ã¼Ä"HIW"¡z¡A¥HµL¼Æµê©Û°g´b$n¡C\n"NOR),me,victim);
                break;
            case 2:
                message_vision(sprintf(HIY"$N¨Ï¥X"HIW"¡y"HIC"¼C¡ã¶Õ¡ã§x¡ã¼Ä"HIW"¡z"HIY"¡A¥HµL¼Æ¼C¶Õ§x¦í$n¡C\n"NOR),me,victim);
                break;
            case 3:
                message_vision(sprintf(HIG"$N¨Ï¥X"HIW"¡y"HIC"¼C¡ã©Û¡ã±þ¡ã¼Ä"HIW"¡z"HIG"¡A¥HµL¼Æ¼C©Û±þ¦V$n¡C\n"NOR),me,victim);
                break;
            case 4:
                message_vision(sprintf(HIC"$N¨Ï¥X"HIW"¡y"HIC"¼C¡ã¾W¡ã·À¡ã¼Ä"HIW"¡z"HIC"¡A¥H¾W§Q¼C¾W±þ·À$n¡C\n"NOR),me,victim);
                break;
         }
           
           victim->receive_damage("kee",dam);
           COMBAT_D->report_status(victim, 1);
      }
      me->add("force",-100);
   }
}
void plan_king1(object me, object victim, object weapon, int damage)
{
   int heal=this_player()->query("max_force")/20;
   if( heal > 1000) heal= 1000;
   if(this_player()->query("kee")<this_player()->query("max_kee") && this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100))
   {
      message_vision(HIW"\n$N¹B°_¸Ö©ö¤ßªk¸Ì¤§¤»ÃüÅ@¨­¤º«l¡A¤@°}¥Õ·Ï±qÀY³»¤W´U¥X¡C\n"NOR,this_player());
	  this_player()->add("kee",heal);
      this_player()->add("force",-heal);
   }
}
void plan_king2(object me, object victim, object weapon, int damage)
{
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100))
   {
      message_vision(HIW"\n$N®³°_¹D¨ã¡y¤»¥Ò¤Ñ®Ñ¡z¡A¤f¤¤©À¥X©G¤å¡AÅý$n¨­¤ß¨ü¨ì·¥¤jªº¶Ë®`¡I\n\n"NOR,this_player(),victim);
	  this_player()->add("sen",-50);
	  victim->receive_damage("sen", 100);
      COMBAT_D->report_status(victim, 1);
	  victim->start_busy(1);
   }
}
void plan_king3(object me, object victim, object weapon, int damage)
{
   int heal=this_player()->query("max_force")/30;
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && 80>random(100) )
   {
        message_vision(HIY"
               $N±N"HIW"©_®Ñ¤»Ãü"HIY"¸m´x¤W¡A¨­¤W®ð«lÄ­ÂÃµÛ¤»ÃüªZ¾Ç
           ¤§Åq¡A$N¥w³Ü°jÀú"HIR"¡y¹BÄw±cØò ¾ÔµL¤£³Ó¡z"HIY"¤£Â_¦V¥|©P§l¤Þ®ð«l¡I\n"NOR,this_player());
      this_player()->add("force",heal);
	  victim->add("force",-heal);
   }
}
void plan_king4(object me, object victim, object weapon, int damage)
{
   damage=this_player()->query("combat_exp")/5000;
   if(this_player()->query("mark/sixgod-plan",1) && this_player()->query("combat_exp")>5000000 && this_player()->query("force")>1000 && 50>random(100) )
   {
   {message_vision("\n\n               "HIR""BMAG"=========="HIW"¡y"HIY"·¥¤õ¤@¥X¡A¸Uª«¨ãµI"HIW"¡z"HIR"==========\n"NOR,this_player());}
   {message_vision("         "HIC""BMAG"¥u¨£$N¤â¤¤ªº"HIG+ weapon->query("name")+HIC""BMAG"¤Û¤Æ¦¨¤@§â§Q¼C¡AºÆ¨gªº¦V$n¨ë¥h¡C\n"NOR,this_player(),victim);}
   {message_vision("\n
[0;1;33m [1m [1m [1m [1;37m [1m¢[1mf[0;31m¢e¢e¢e¢e[37m [0;1;32m¢[1mn[0;31;42m:[0;1;37;44m¢[1m¨[1;40m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1mi[1m¢[1m©[0m
[0;1m [1m [1m [1;36m [1m [1;30;47m¢[1mc[0;32;41m¢d¢d¢d¢d[37;40m ¢n[31;42m:[37;44m¢ª[40m¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢h¢«   [0m

   \n",this_player());}
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤@¦¡"HIW"¡y"NOR"¦æ¶³¬y"HIB"¤ô"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤G¦¡"HIW"¡y"HIG"¤C¨B¦¨"HIC"¸Ö"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤T¦¡"HIW"¡y"HIW"§â"HIR"°s"NOR"°Ý¤Ñ"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim); }
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¥|¦¡"HIW"¡y"HIY"µâ"HIM"¶éºÉ¿³"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤­¦¡"HIW"¡y"HIR"©í¨B±×¦æ"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤»¦¡"HIW"¡y"NOR"ªïªù"HIB"ÅK"HIR"®°"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤C¦¡"HIW"¡y"HIB"Â½"HIR"ªá"HIY"»R"HIG"³S"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤K¦¡"HIW"¡y"HIB"­·"NOR"±½"HIR"±öªá"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤E¦¡"HIW"¡y"HIB"»í¬P"HIM"ÂI"NOR"¤æ"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);  
        {message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk²Ä¤Q¦¡"HIW"¡y"NOR"Âà"HIB"Às"HIG"°j"HIR"¤é"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);
		{message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk¤Q¤@¦¡"HIW"¡y"HIB"¶³"HIR"¶}"HIY"Às"HIB"ÄË"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);}
        COMBAT_D->report_status(victim, 1);
		{message_vision(HIC"$N§Ö·Nªº¨Ï¥X¦æ¶³¬y¤ôµ§ªk¤Q¤G¦¡"HIW"¡y"HIB"ÆF"HIR"Às"HIY"µ§"HIB"®Ñ"HIW"¡z"HIC"¡Aµ§·N·½·½¤£µ´ªº¦V$n¨ë¥h¡I\n"NOR,this_player(),victim);
      this_player()->add("force",-500);
	  victim->receive_wound("kee",damage);
		}
   }
}





int valid_enable(string usage)
{
   return (usage=="stabber")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
// skill level < 40 ¥u¯à¨Ï¥Î«e 9 ©Û
if( me->query_skill("knowpen",1) < 40)
      return action[ random( sizeof( action)- 4)];
// skill level > 50 ¤£¨Ï¥Î«e 4 ©Û...¼W¥[¯S§ð¨Ï¥Î²v...
   else
      return action[ random( sizeof( action)- 4)+ 4];
}

// ³o­Ó¥u¬O¬d¸ß¬O§_¥i¥H½m²ß, ¼W¥[ skill ¤£¬O¦b³o¨à.
int practice_skill(object me)
{
   object weapon;

   me->receive_damage("sen",30);
   if (me->query_skill("literate")*2<me->query_skill("knowpen"))
      return notify_fail("§AªºÅª®ÑÃÑ¦r¤£°÷¡M¤£¯à»â®©¨ä¤¤ªº¹D²z¡C\n");
   if( !objectp(weapon = me->query_temp("weapon")) ||
      ( string)weapon->query("skill_type")!="stabber")
   {
      return notify_fail("§A­n¦³¾A¦XªºªZ¾¹¤~¯à½m¦æ¶³¬y¤ôµ§ªk¡C\n");
   }

   if( ( int)me->query("sen")<30)
      return notify_fail("§Aªº¯«¤£°÷¡M¤£¯à½m¦æ¶³¬y¤ôµ§ªk¡C\n");
   return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("scholar")+"/knowpen/"+action;
}
