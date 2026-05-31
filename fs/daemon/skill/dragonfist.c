#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object weapon, int damage);
void attack2(object me, object victim, object weapon, int damage);
void attack3(object me, object victim, object weapon, int damage);
void again1(object me, object victim, object weapon, int damage);


mapping *action = ({
//0
(["action":"$N¥ª»L·L¦±¡A¥kÁu¤ºÅs¡A¥k´xµe¤F­Ó¶ê°é¡A°_¤â¡u"+HIY"¤®Às¦³®¬"NOR+"¡v¡A©Iªº¤@Án¦V¥~±À¥h¡A
´x«lª½ª½ªº±½¦V$nªº$l¡C",
"dodge":-60,
"parry":50,
"force":60,
"damage":325,
"damage_type" : "·ï¶Ë",
]),
//1
(["action":"$N¾®¯«´£®ð¡AÂù¸}¤@ÃÞ¡A¨­Åé¤£¦í°ªÅD¡AÂù´x¦p¤M¦ü°Å¡A¤@©Û¡u"+HIY"­¸Às¦b¤Ñ"NOR+"¡v¡A´x´x©¹
$nªº$l«d¥h¡C",
"dodge":-60,
"parry":50,
"force":70,
"damage":330,
"damage_type" : "·ï¶Ë",
]),
//2
(["action":"$Nªº´x¶Õ¸U°¨©bÄË¡A¦³­Y¶}¤ÑÅP¦a¯ë¡A¡u"+HIY"¾ÔÀs¦b³¥"NOR+"¡v¦p¤@±ø¨gÀs¯ë¼³¦V$n¡A¶Õ¤£¥iÀÉ¡C",
"dodge":-90,
"parry":80,
"force":100,
"damage":335,
"damage_type" : "·ï¶Ë",
]),
//3
(["action":"$N¥k¤â©}°_­¹¤¤¨â«ü¡A¥b®±¥b´x¡A¦V$nªº$l¥´¥h¡A¡u"+HIY"¼çÀs¤Å¥Î"NOR+"¡v©Û·Nãé¦±¤£½a¡A¥ª¤â
¦P®É¦VùØ¹_®³¡A¥k±À¥ª¹_¡A·¥Ãø°{Á×¡C",
"dodge":-90,
"parry":80,
"force":100,
"damage":340,
"damage_type" : "·ï¶Ë",
]),
//4
(["action":"$N¥k´x¤@¶}¡A¥ª´x¸òµÛ¤@´¤¡A¤O»E©ó´x¡A¡u"+HIY"§Q¯A¤j¤t"NOR+"¡v®ð¶Õ¤j¶}¤jÂó¡A´x«lºÉ³z­è®ð¡A
¦V$n¤£Â_±À¥h¡C",
"dodge":-90,
"parry":80,
"force":100,
"damage":345,
"damage_type" : "·ï¶Ë",
]),
//5
(["action":"$NÂù´x¤@´£¡AÂùÁu¤ºÅs¯u®ðÀH¤§¤@¦R¡A¡u"+HIY"ÂEº¥©ó³°"NOR+"¡v´x¶Õ¥ÑÁô¦Ó©ú¡A¥­¥­ªº±À¦V$n¡C",
"dodge":-90,
"parry":80,
"force":100,
"damage":350,
"damage_type" : "·ï¶Ë",
]),
//6
(["action":"$N¨­§Î½wºC±À°Ê¡A°¿¦a¶¡Âù´x¶¶¶Õ¤@±À¡A¡u"+HIY"¬ð¦p¨ä¨Ó"NOR+"¡v§Ï¦p¼É«BÆJ¦Ü¡A´x«l¦p¨g­·¯ë¦a
Å§¦V$n¡C",
"dodge":-100,
"parry":80,
"force":100,
"damage":355,
"damage_type" : "·ï¶Ë",
]),
//7
(["action":"$N´x¶Õ¤j¶}¤jÂó¡AÅé¤º¯u®ð¤£Â_¦V¥~©ñ®g¡A©Û¦¡¥çÀHµÛ¯u®ð¦V$n§ð¥h¡A¡u"+HIY"¾_Åå¦Ê¨½"NOR+"¡v¦p
Ãz¹p¯ëÅå¤H¡C",
"dodge":-100,
"parry":80,
"force":100,
"damage":360,
"damage_type" : "·ï¶Ë",
]),
//8
(["action":"$NÀþ®É§l¤@¤f®ð¡A¥ª´x«e±´¡A¥k´x°¿¦a±q¥ª´x©³¤U¬ï¤F¥X¥h¡A±j©Û¡u"+HIY"©ÎÅD¦b²W"NOR+"¡vª½À»
¦V$nªº$l¡C",
"dodge":-100,
"parry":80,
"force":110,
"damage":365,
"damage_type" : "·ï¶Ë",
]),
//9
(["action":"$N§Î¦p²rªê¥X¬]¡A¬½©Û¡u"+HIY"¯«ÀsÂ\\§À"NOR+"¡v©I¤§±ý¥X¡AÀH§Y¤Ï¤â¤@¼A¡AÀ»¦V$nªº$l¡C",
"dodge":-100,
"parry":90,
"force":110,
"damage":370,
"damage_type" : "·ï¶Ë",
]),
//10
(["action":"$N´x¦¬©ó¯Ý¡A©Û¦¡¿\\¦Ó¤£µØ¡AÂù¤â¼»´x¤@¦X¡A¡u"+HIY"¨£Às¦b¥Ð"NOR+"¡vµ§ª½ªºÀ»¦V$nªº$l¡C",
"dodge":-100,
"parry":90,
"force":110,
"damage":375,
"damage_type" : "·ï¶Ë",
]),
//11
(["action":"$NÂù´x¦P®É¤@Á|¡A¸òµÛ­I¯á©¹«e¤@®¼¡AÂù´x»ôµo¡A¤@©Û¡u"+HIY"ÂùÀs¨ú¤ô"NOR+"¡v§ð¦V$n¡C",
"dodge":-100,
"parry":90,
"force":110,
"damage":380,
"damage_type" : "·ï¶Ë",
]),
//12
(["action":"$N´x«l¤@ÃP¡A¤O³zÂH«l¡A¥ª´x¤@±a¡A²o°Ê$n¥|¤è®ð¬y¡A¡u"+HIY"¸sÀsµL­º"NOR+"¡vÂù´x¦p¨g«BÀ»¥X¡A
´x«lµê¤ÛÄÆ´ù¥O$n²´ªá¼º¶Ã¡C",
"dodge":-100,
"parry":90,
"force":110,
"damage":385,
"damage_type" : "·ï¶Ë",
]),
//13
(["action":"$N¨­§Î¤£Â_®Ì°Ê¡A¨B²¾$n¤»¤è¡A¬ðµM¶¡¡A¤»¤è´x¼v¦P®É¨gÅ§¦Ó¦Ü¡A¡u"+HIY"®É­¼¤»Às"NOR+"¡v¦p¸sÀs
°f¾½¡AºÉÀ»¦V$n¡C",
"dodge":-100,
"parry":100,
"force":200,
"damage":390,
"damage_type" : "·ï¶Ë",
]),
//14
(["action":"$N´x¼v¦u¦í¥þ¨­¡A¨Ã¤£·m§ð¡A$n«o¤Ï³Q$NÁc±Kªº´x¼v©Ò°h¡A¦u©Û¡u"+HIM"±K¶³¤£«B"NOR+"¡v¦p¤j«B±ý
¨Ó¡A¤@´x¤S¤@´xÀôÂ¶$n¡C",
"dodge":-110,
"parry":100,
"force":200,
"damage":395,
"damage_type" : "·ï¶Ë",
]),
//15
(["action":HIW"                $N¨Ï¥X­°Às¥¢¶Çµ´¾Ç²Ä¤@¦¡\n"
"             ¡Ð¡×"HIG"¡uŸV·l¡Ð«h¡Ð¦³¡Ð§·Ÿ]¡v"HIW"¡×¡Ð\n"
"          ¤º®§¤£Â_´£ª@¡A¬ðµM¯u®ðÃz¦R¡A¤º«l¤Ï¥ÑÂù´xÄ­¥Í\n"
"            ©Û·N³Q"HIG"¬~Åè«l"HIW"©Ò¿Eµo¡A¥Ñ¸Ì¦Ó¥~¤£Â_«IÅ§$n¡C\n"NOR,
"dodge":-110,
"parry":100,
"force":220,
"damage":400,
"damage_type" : "¤º¶Ë",
"post_action" : (: attack1 :),
]),
//16
(["action":HIW"                $N¨Ï¥X­°Às¥¢¶Çµ´¾Ç²Ä¤G¦¡\n"
"             ¡Ð¡×"HIC"¡uŸW¼i¡ÐÁ÷¡Ð¦B¡Ð¦ÜŸ\\¡v"HIW"¡×¡Ð\n"
"$Nµyµy¦R¤F¤@¤f®ð¡A°f¹BÅé¤º¬~Åè¸g¡A±N"HIR"¶§­è¤§®ð"HIW"Âà¤Æ¬°"HIB"³±¬X¤§«l\n"HIW
"   ¨â¨y©¹¤W·L©ï¡A±N³±¬X¤§«l¹B¦ÜÂùÁu¡A¥k®±¥ª´x¡Aª½À»¾î±À\n"
"     ¤Û¤Æ¥X¨â¹D"HIC"¦BÀs"HIW"¡A­è¬X¨ÃÀÙ¡A¤@§Ö¤@ºCªº¥´¦V$nªº$l¡C\n"NOR,
"dodge":-120,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "­á¶Ë",
"post_action" : (: attack2 :),
]),
//17
(["action":HIW"                $N¨Ï¥X­°Às¥¢¶Çµ´¾Ç²Ä¤T¦¡\n"
"             ¡Ð¡×"HIM"¡uŸXÖô¡Ð¦Ï¡ÐÄ²¡ÐÃ¿Ÿ[¡v"HIW"¡×¡Ð\n"
"          $N¹B°_¬~Åè¸g¤Q¦¨¥\\¤O¡A±N¯u®ð¹B¦ÜÂù¤â¡A¾®®ð¬°¼C\n"
"³s¼C±a´x¡AµL¼Æ"HIY"¥ú¨~"HIW"¦³¦p"YEL"¨³"HIY"¹p"BLU"¯e"HIB"­·"HIW"¦V$n¬Û¤¬¿EÀú¦Ó¥h¡A´x·N¼C·N¦P®ÉÀ»¦V$n¡C\n"NOR,
"dodge":-150,
"parry":100,
"force":250,
"damage":400,
"damage_type" : "¨ë¶Ë",
"post_action" : (: attack3 :),
]),
//18
(["action":HIW"$N¦V«áÂ½¨­¤@ÅD¡A°h«á¼Æ¤Ø¡A¥þ¤O¹ª¶ÊÅé¤ºªº"HIY"­°Às«l"HIW"¡A¤º«l¦p¼é¼É´é¡A²o°Ê¥|¤è®ð¬y¡A´ý¨­«_¥X°}°}¥Õ·Ï¡C\n"
"¥Õ·ÏÂ·Â¶¡A¨­«á¤Û¤Æ¥X¦p¯u¦ü°²ªº"HIC"Às§Î®ð«l"HIW"¡A¥|©P®ð¬y¬Û¤¬¿EÀú¡A¾_ªº$n¦å¯ß¯¿¶Ã¡C\n"
"¥u¨£$N¶ÆµMÁq¥ß¡Aª¬¬Æ¥­ÀR¡A¦ý¨ä¨­«áªº"HIB"Às§Î®ð«l"HIW"¡A«o¦p½b¦b©¶¡A¦³­¸Às¦b¤Ñ¤§«Â¡C\n\n"NOR
"       ÀK®É$N"HIY"»¨¥ú"NOR"¼É²{¡AÅé¤º­°Às«l¯}Åé¦Ó¥X¡A¨Ï¥X­°Às³Ì²×¶ø¸q¡C\n"NOR
HIW"            ¢w¡×"HIR"ŸY Às  ¼S  ¤E  ¤Ñ ŸZ"HIW"¡×¢w"NOR,
"dodge":-100,
"parry":100,
"force":150,
"damage":400,
"post_action":  (: again1 :),
"damage_type" : "·ï¶Ë",
]),

});


mapping query_action(object me, object *weapon)
{
   int skill;

   skill=me->query_skill("dragonfist", 1);

   if( me->query("family/family_name")!="¤¢À°" || !me->query("read_page_1",1)
       || !me->query("read_page_2",1) || !me->query("read_page_3",1)
       || !me->query("read_dragonfist",1) )
   {
    if( skill < 50)
       return action[random(7)];
    else if( skill < 60)
       return action[random(10)];
    else if( skill < 70)
       return action[random(12)];
    else if( skill < 80)
       return action[random(14)];
    else
       return action[random(15)];
   } else {if (random(100) > 80 )
       return action[random(10)+9];
    else 
       return action[random(9)+9];
   }
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist", 1);
 att_value = random(2*skill);
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG"$NÂù´xÄ­§tªº¬~Åè«l¦³¦p¼F¹p¯e­·ªº¦V$n­¸©b¦Ó¥h¡A$nµw¾×¤§¤U¬~Åè«l¤w¬ïÅé¦Ó¹L¡A¾_¶Ë¤F$nªº¤ß¯ß\n"NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("hart",random(15));
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("dragonfist", 1);
 busy_value = skill / 50;
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIC"¨â¹D³±¬X§N¨æ«l®ðÂ«¤J$NªºÅé¤º¡A©_´H»k°©¨Ï$N¤@®ÉµLªk¦æ°Ê¡C\n"NOR,victim);
   victim->start_busy( random(busy_value) );
   COMBAT_D->report_status(victim, 1);
   victim->apply_condition("cold",random(15));
  }
}


void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("dragonfist",1);
 att_value=random(2*skill);
 if((me->query_skill_mapped("force")=="dragonforce")&&(me->query("force_factor") >= 1 ))
 {
  message_vision(HIM"$N§C³Ü¤@Án¡A±N´x¤¤¼C®ð®g¦V$n¡AµL¼Æ¼C¯í¿E®g¦Ó¥h¡A$nÁ×µL¥iÁ×¡AºG¾D¼C®ð¬ïÅé¡C\n"NOR,me,victim);
  victim->add("kee",-att_value);
  COMBAT_D->report_status(victim,1);
  victim->apply_condition("swordkee",random(15));
 }
}

void again1(object me, object victim, object weapon, int damage)
{
 int skilv,maxlv,i,j,mydamage;
 skilv=random(me->query_skill("dragonfist",1));
 maxlv=me->query_skill("dragonfist",1);
 j=skilv/10;
 if(j>9) {j=9;}
 for(i=0;i<=j;i++)
 {
  switch(i)
  {
  case 0:
  message_vision("$N¥ª»L·L¦±¡A¥kÁu¤ºÅs¡A¥k´xµe¤F­Ó¶ê°é¡A°_¤â¡u"+HIY"¤®Às¦³®¬"NOR+"¡v¡A©Iªº¤@Án¦V¥~±À¥h¡A´x«lª½ª½ªº±½¦V$n¡C\n",me,victim);
  break;
  case 1:
  message_vision("$N¾®¯«´£®ð¡AÂù¸}¤@ÃÞ¡A¨­Åé¤£¦í°ªÅD¡AÂù´x¦p¤M¦ü°Å¡A¤@©Û¡u"+HIY"­¸Às¦b¤Ñ"NOR+"¡v¡A´x´x©¹$n¥|ªÏ°Å¥h¡C\n",me,victim);
  break;
  case 2:
  message_vision("$Nªº´x¶Õ¸U°¨©bÄË¡A¦³­Y¶}¤ÑÅP¦a¯ë¡A¡u"+HIY"¾ÔÀs¦b³¥"NOR+"¡v¦p¤@±ø¨gÀs¯ë¼³¦V$n¡A¶Õ¤£¥iÀÉ¡C\n",me,victim);
  break;
  case 3:
  message_vision("$N¥k¤â©}°_­¹¤¤¨â«ü¡A¥b®±¥b´x¡A¦V$n¥´¥h¡A¡u"+HIY"¼çÀs¤Å¥Î"NOR+"¡v©Û·Nãé¦±¤£½a¡A¥ª¤â¦P®É¦VùØ¹_®³¡A¥k±À¥ª¹_¡A·¥Ãø°{Á×¡C\n",me,victim);
  break;
  case 4:
  message_vision("$N§Î¦p²rªê¥X¬]¡A¬½©Û¡u"+HIY"¯«ÀsÂ\\§À"NOR+"¡v©I¤§±ý¥X¡AÀH§Y¤Ï¤â¤@¼A¡AÀ»¦V$n¡C\n",me,victim);
  break;
  case 5:
  message_vision("$N´x¦¬©ó¯Ý¡A©Û¦¡¿\\¦Ó¤£µØ¡AÂù¤â¼»´x¤@¦X¡A¡u"+HIY"¨£Às¦b¥Ð"NOR+"¡vµ§ª½ªºÀ»¦V$n¡C\n",me,victim);
  break;
  case 6:
  message_vision("$NÂù´x¦P®É¤@Á|¡A¸òµÛ­I¯á©¹«e¤@®¼¡AÂù´x»ôµo¡A¤@©Û¡u"+HIY"ÂùÀs¨ú¤ô"NOR+"¡v§ð¦V$n¡C\n",me,victim);                                             break;
  case 7:
  message_vision("$N´x«l¤@ÃP¡A¤O³zÂH«l¡A¥ª´x¤@±a¡A²o°Ê$n¥|¤è®ð¬y¡A¡u"+HIY"¸sÀsµL­º"NOR+"¡vÂù´x¦p¨g«BÀ»¥X¡A´x«lµê¤ÛÄÆ´ù¥O$n²´ªá¼º¶Ã¡C\n",me,victim);
  break;
  case 8:
  message_vision("$N¨­§Î¤£Â_®Ì°Ê¡A¨B²¾$n¤»¤è¡A¬ðµM¶¡¡A¤»¤è´x¼v¦P®É¨gÅ§¦Ó¦Ü¡A¡u"+HIY"®É­¼¤»Às"NOR+"¡v¦p¸sÀs°f¾½¡AºÉÀ»¦V$n¡C\n",me,victim);
  break;
  }
   if( ((int)victim->query_skill("move",1)
        + random((int)victim->query_skill("dodge",1))*5)
        < skilv+random((int)me->query_skill("dodge",1)*i
        + (int)victim->query_skill("move",1)) )
    {
     message_vision(HIC"$Nªº«l¤O¼ê´û¬¤´é¡A$n¤@®É©Û¬[¤£¦í¡A³Q$N¤@´xÅF¤¤¡A¡u«z¡I¡v¤@Án¦R¥X¤@¤fÂA¦å¡I¡I\n"NOR,me,victim);
     victim->receive_damage("kee",(skilv*i/10));
     COMBAT_D->report_status(victim,1);
     me->add("force",-(skilv*maxlv/100));
     mydamage = mydamage+(skilv*i)/10;
   } else
   {
    message_vision(HIW"$n¦b´x¼vªº¥]³ò¤§¤U¡A¬Ý¥X$Nªº¯}ºì¡A¥ª°{¥k¸úªº¸ú¹L¤F$N­â¼Fªº±þ©Û\n"NOR,me,victim);
     me->add("force",-skilv*maxlv/100);
     mydamage = mydamage+(skilv*i)/10;
   }
 }
 if(i>=9)
 {
  message_vision(HIR"$N¨Ï¥XÀs¼S¤E¤Ñ«á¤º¤O¯Ó·l¹L¥¨¡A®ð®§¤j¶Ã¡A©I§l¨I­«¥|ªÏ»ÄµhÃø©`¡A¤£±o¤£»°ºò¹B®ð½Õ®§¡C\n"NOR,me);
        me->start_busy((skilv+maxlv)/50);
        COMBAT_D->report_status(victim,1);
 } else {
 message_vision(HIR"$NÀ»¥X"+chinese_number(i)+"´x«á¡A¯u®ð¤@´²¡A¤º¤OµL¥H¬°Ä~¡A¤Ï³Q­°Às«l©Ò¶Ë¡A¦R¥X¤@¤fÂA¦å¡I\n"NOR,me);
 me->start_busy((skilv+maxlv)/100);
 me->receive_damage("kee",mydamage);
 COMBAT_D->report_status(victim,1);
 }
}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<1000)
  return notify_fail("§AªZ¾Çª¾ÃÑ¤£¨¬¡AµLªk°Ñ³z­°Àsµ´¾Çªººë§®¤§³B\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/dragonfist/"+action;
}
int valid_learn(object me)
    {
        if( me->query("max_force") < 1500 ) {
            tell_object(me, "§Aªº¤º¤O­×¬°¤£°÷, ³Ì¤Ö­n¦³¤@¤d¤­¦ÊÂI¡C\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "¥u¦³¤¢À°§Ì¤l¤~¯à¾Ç­°Àsµ´¾Ç¡C\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "¤¢À°§Ì¤l­n§¹¦¨¥ô°È¤Q¤~¯à¾Ç¡C\n");
            return 0;
        }
        if( me->query_str() < 20) {
            tell_object(me, "§AªºÁu¤O¤£°÷¤£¯à¾Ç­°Àsµ´¾Ç¡C\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "§A¥Ø«eªº¤º¤O¤£¨ì¤­¦ÊÂI, µLªk½m¦¹µ´¾Ç¡C\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 3 ) {
            tell_object(me, "§Aªº¼ç¯à¤£¨ì¤TÂI, µLªk½m¦¹µ´¾Ç¡C\n");
            return 0;
        }
       if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
       return   notify_fail("¾Ç­°Às¤Q¤K´x¥²¶·ªÅ¤â¡C\n");

        tell_object(me, "¾Ç¦¹µ´¾Ç»Ý¦©¼ç¯à¤TÂI¡C\n");
        me->add("potential", -3);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="unarmed" )||(usage=="parry");
}


