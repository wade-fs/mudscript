// fusword.c

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me, object victim, object  weapon, int damage);

string *parry_msg=
    ({
      "$n使出神龍絕學中的神龍劍法，將$N的武器盪了出去。\n",
      "$n手中長劍飛舞，『噹』的一聲，將$N的攻勢盡數檔了下來。\n",
      "$n手腕翻轉，一劍平平擊出，巧妙的化解了$N的招式。\n",
      "$n一劍擊向$N的要穴，逼的$N回身擋劍，正是防禦之最高境界\n",
    });
string *array_msg=
    ({
      "[1;33m$N帶領著眾劍士，腳踩八卦，劍化兩儀，將神龍劍法發揮到極致。\n[0m",
      "[1;33m眾人愈戰愈順，愈戰愈勇，令敵人望之膽怯。\n[0m",
      "[1;33m$N指揮若定，眾人劍招一招招遞向敵人，配合的天衣無縫。\n[0m",
     }); 
mapping *action = ({
        ([      
                "action"     :               "$N突然領悟了『劍隨心發』的道理，弓身屈腿向前彈出，正是一招『乳燕穿林』。",
                "dodge"      :               -25,
                "parry"      :                20,
                "damage"     :                250,
                "damage_type":               "刺傷"
        ]),
        ([     
                "action"     :               "$N握劍之手一緊，奮力向前刺出，一招『雷霆萬鈞』攻向$n。",
                "dodge"      :               -30,
                "parry"      :                25,
                "damage"     :                300,
                "damage_type":               "刺傷"
        ]),
        ([   
                "action"     :               "$N氣如九珠行遍周身大穴，力貫劍尖，僕布橫掃，正是一招『風起雲湧』",
                "dodge"      :                -30,
                "parry"      :                30,
                "damage"     :                400,
                "damage_type":               "刺傷"
        ]),
        ([  
                "action"     :               "$N手中之劍，幻化起無數劍圈，霍霍劍光將$n包圍其中，正是一招『運轉乾坤』",
                "dodge"      :               -30,
                "parry"      :                30,
                "damage"     :                500,
                "damage_type":               "刺傷"
        ]),
        ([ 
                "action"     :               "$N凝氣於劍，手中之劍忽然向前飛去，正是一招『長虹貫日』，去勢之疾使$n不及招架",
                "dodge"      :               -30,
                "parry"      :                20,
                "damage"     :                650,
                "force"      :                130,
                "damage_type":               "割傷"
        ]),
        ([
                "action"     :               "$N忽然躍起丈餘，由半空中向$n疾攻而至正是一招『飛龍在天』",
                "dodge"      :               -20,
                "parry"      :                35,
                "damage"     :                850,
                "force"      :                100,
                "damage_type":               "刺傷"
        ]),
         ([     "action"     :               "$N瞭悟了劍法上『連綿不絕』之真義，手中佩劍一盪連使出『乳燕穿林』『雷霆萬鈞』『風起雲湧』，分攻$n周身大穴",
                "dodge"      :                -35,
                "parry"      :                30,
                "damage"     :                1000,
                "force"      :                100,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
           ]),
          ([    "action"     :               "$N領悟了『以氣御劍』之真義，運氣於指控制空中之劍攻向$n。正是傳說中的『御劍術』",
                "dodge"      :                -40,
                "parry"      :                40,
                "damage"     :                1100,
                "force"      :                110,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
            ]),
            ([  "action"     :                "$N領悟了所謂『以靜制動』，立即心如明鏡，看出$n的破綻，一連使出『乳燕穿林』『雷霆萬鈞』『風起雲湧』『運轉乾坤』『長虹貫日』劍氣形成漩渦將$n包圍其中",
                "dodge"      :                -30,
                "parry"      :                45,
                "damage"     :                1500,
                "force"      :                120,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
             ]),
             ([ "action"     :                "$N已得劍法精要，一眼看對穿$n之招式，隨手一劍便破解他的招式並將其重創，正是劍法之極至『無招勝有招』",
                "dodge"      :                -40,
                "parry"      :                45,
                "damage"     :                1700,
                "force"      :                120,
                "post_action":                (: berserk :),
                "damage_type":                "割傷",
             ]),
            ([  "action"     :                "$N面露微笑，仰視蒼天，待$n攻勢已近，只見空中劍花閃閃，$N從容的收劍回竅，$n卻已受到身受重傷",
                "dodge"      :                -45,
                "parry"      :                50,
                "damage"     :                2000,
                "force"      :                130,
                "post_action":               (: berserk :),
                "damage_type":                "割傷",
             ]),            
             
   });
int valid_learn(object me)
{
       if( !me->query_temp("weapon") )
        return   notify_fail("練神龍劍術必需先拿把劍。\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}

string query_parry_msg(string limb)
{
  int parry_pow;
  object me;
  me=this_player();
        parry_pow = (int)( me->query_skill("fuswords", 1)/10);
          if ( parry_pow <= 5)
                return parry_msg[random(2)];
            else

                return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
       int skill_level, limit,i;
	   object victim,*enemy;
		enemy = me->query_enemy();
		i=sizeof(enemy);
        victim = enemy[random(i)];
        skill_level = (int)(me->query_skill("fuswords", 1));
        limit= (int)(skill_level/8);
        if( me->query_temp("use_form",1))
          message_vision( array_msg[random(sizeof(array_msg))],me );
if(me->query_temp("weapon"))
{
 weapon=me->query_temp("weapon");  //扣自己force 200
if((me->query("class")=="dancer")&&(weapon->query("id")=="dragon sword"))
  {
if(me->query("id")==("cgy"))
{
message_vision(HIC + "$N使出神龍劍法終極奧義,只見一條火龍朝著$n直撲而去\n" + NOR,me,victim);
message_vision(HIR + "                                        &.  &.     .\n" + NOR,me,victim);
message_vision(HIR + "                                        ~ss.&ss. .s'\n" + NOR,me,victim);
message_vision(HIR + "                                .     .ss&&&&&&&&&&s.\n" + NOR,me,victim);
message_vision(HIR + "                                &. s&&&&&&&&&&&&&&`&&Ss\n" + NOR,me,victim);
message_vision(HIR + "                                ~&&&&&&&&&&&&&&&&&&o&&&       .\n" + NOR,me,victim);
message_vision(HIR + "                               s&&&&&&&&&&&&&&&&&&&&&&&&s.  .s\n" + NOR,me,victim);
message_vision(HIR + "                              s&&&&&&&&&~&&&&&&~~~~&&&&&&~&&&&&.\n" + NOR,me,victim);
message_vision(HIR + "                              s&&&&&&&&&&s~~&&&&ssssss~&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&'         `~~~ss~&~&s~~\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&.              `~~~~~&  .s&&s\n" + NOR,me,victim);
message_vision(HIR + "                             s&&&&&&&&&&&&s....               `s&&'  `\n" + NOR,me,victim);
message_vision(HIR + "                         `ssss&&&&&&&&&&&&&&&&&&&&####s.     .&&~&.   . s-\n" + NOR,me,victim);
message_vision(HIR + "                           `~~~~&&&&&&&&&&&&&&&&&&&&#####&&&&&&~     &.&'\n" + NOR,me,victim);
message_vision(HIR + "                                 ~&&&&&&&&&&&&&&&&&&&&&####s~~     .&&&|\n" + NOR,me,victim);
message_vision(HIR + "                                  ~&&&&&&&&&&&&&&&&&&&&&&&&##s    .&&~ &\n" + NOR,me,victim);
message_vision(HIR + "                                   &&~~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~   `\n" + NOR,me,victim);
message_vision(HIR + "                                  &&~  ~&~&&&&&&&&&&&&&&&&&&&&S~~~~'\n" + NOR,me,victim);
message_vision(HIR + "                             .   .~     '  &&&&&&&&&&&&&&&&####s\n" + NOR,me,victim);
message_vision(HIR + "                             &.          .s&&&&&&&&&&&&&&&&&####~\n" + NOR,me,victim);
message_vision(HIR + "                 .           ~&s.   ..ssS&&&&&&&&&&&&&&&&&&&####~\n" + NOR,me,victim);
message_vision(HIR + "                 &           .&&&S&&&&&&&&&&&&&&&&&&&&&&&&#####~\n" + NOR,me,victim);
message_vision(HIR + "                 Ss     ..sS&&&&&&&&&&&&&&&&&&&&&&&&&&&######~~\n" + NOR,me,victim);
message_vision(HIR + "                  ~&&sS&&&&&&&&&&&&&&&&&&&&&&&&&&&########~\n" + NOR,me,victim);
message_vision(HIR + "           .      s&&&&&&&&&&&&&&&&&&&&&&&&#########~~'\n" + NOR,me,victim);
message_vision(HIR + "           &    s&&&&&&&&&&&&&&&&&&&&&#######~~'      s'         .\n" + NOR,me,victim);
message_vision(HIR + "           &&..&&&&&&&&&&&&&&&&&&######~'       .....&&....    .&\n" + NOR,me,victim);
message_vision(HIR + "            ~&&&&&&&&&&&&&&&######~' .     .sS&&&&&&&&&&&&&&&&s&&\n" + NOR,me,victim);
message_vision(HIR + "              &&&&&&&&&&&&#####~     &. .s&&&&&&&&&&&&&&&&&&&&&&&&s.\n" + NOR,me,victim);
message_vision(HIR + "   )          &&&&&&&&&&&#####'      `&&&&&&&&&###########&&&&&&&&&&&.\n" + NOR,me,victim);
message_vision(HIR + "  ((          &&&&&&&&&&&#####       &&&&&&&&###~       ~####&&&&&&&&&&\n" + NOR,me,victim);
message_vision(HIR + "  )\\         &&&&&&&&&&&&####.     &&&&&&###~             ~###&&&&&&&&&   s'\n" + NOR,me,victim);
message_vision(HIR + " (   )        &&&&&&&&&&&&&####.   &&&&&###~                ####&&&&&&&&s&&'\n" + NOR,me,victim);
message_vision(HIR + " )  ( (       &&~&&&&&&&&&&&#####.&&&&&###'                .###&&&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + " (  )  )   _.&~   &&&&&&&&&&&&######.&&##'                .###&&&&&&&&&&\n" + NOR,me,victim);
message_vision(HIR + " ) (  ( \\.         ~&&&&&&&&&&&&&#######....          ..####&&&&&&&&&&&~\n" + NOR,me,victim);
message_vision(HIR + "(   )& )  )        .&&&&&&&&&&&&&&&&&&####################&&&&&&&&&&&~\n" + NOR,me,victim);
 message_vision(HIR + "(   (&&  ( \\     _sS~  `~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&S&&.\n" + NOR,me,victim);
message_vision(HIR + " )  )&&&s ) )  .      .   `&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&~'  `&&\n" + NOR,me,victim);
message_vision(HIR + "  (   &&&Ss/  .&.    .&..s&&&&&&##S&&&&&&&&&&&&&&&&&&&&&&&&S~~        '\n" + NOR,me,victim);
message_vision(HIR + "    \\)_&&&&&&&&&&&&&&&&&&&&&&&##~  &&        `&&.        `&&.\n" + NOR,me,victim);
message_vision(HIR + "        `~S&&&&&&&&&&&&&&&&&#~      &          `&          `&\n" + NOR,me,victim);
message_vision(HIR + "            `~~~~~~~~~~~~~'         '           '           '\n\n\n" + NOR,me,victim);

 
message_vision(HIR + "$n被火龍所吞噬,瞬時全身是火痛苦不己。\n" + NOR,me,victim);
victim->add("kee",-100000);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim, 1);
  

me->add("force",-200);
}
}
}
        if (limit < 1 )
                return action[random(1)];
        if (limit < 2 )
                return action[random(2)];
        if (limit < 3)
                return action[random(3)];
        if (limit < 4)
                return action[random(4)];
        if (limit <5 )
                return action[random(4)+1];
        if (limit <6 )
                return action[random(4)+2];
        if (limit <7)                        
                return action[random(4)+3];
        if (limit <8)
                return action[random(4)+4];
        if (limit <9)
                return action[random(4)+5];
        if (limit <10)
                return action[random(4)+6];
        else
                return action[random(4)+6];
}

void berserk(object me, object victim, object  weapon, int damage)
{ 
     if( (int)me->query_skill("fuswords",1) > random(60)+35 && me->query("force_factor")>= random(5) && me->query("force")>30)
        { 
         if(!me->query_temp("berserk" ))
          {
             if(me->query("name")=="傅劍寒")
             {
              message_vision( sprintf("[1;33m只見$N劍招一緩，萬點劍光倏然消失，化為一道劍虹向著$n的胸前狂奔而去，正是一招『萬流歸宗』對$n造成了莫大的傷害。\n [0m"), me ,victim);
              victim->add("kee",-120);
              me->add("force",-10);
              }
                me->set_temp("berserk", 1);
            }
             me->delete_temp("berserk");
          }
      
} 


int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}
