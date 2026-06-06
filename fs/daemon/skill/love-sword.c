//需配合dream-blade,易水樓之二skill
//edit by Trf
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
inherit F_FUNCTION;
void seven(object me,object victim,object weapon,int damage);
void lockman(object me,object victim,object weapon,int damage);
void four_kill(object me,object victim,object weapon,int damage);
int five_kill(object me,object victim,object weapon,int damage);
void lovekill(object me,object victim,object weapon,int damage);
void power_slash(object me,object victim, object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void dream(object me,object victim,object weapon,int damage);
void fast(object me,object victim,object weapon,int damage);
void disenforce(object me, object victim, object weapon, int damage);
void two(object me,object victim,object weapon,int damage);

mapping *action = ({
//1-8招是情劍
//1
([ "action" :NOR + "                                  " + HBRED + "==那一劍的驚豔==" + NOR + "\n" + NOR+
             HIW + "$N已挐了$w" + HIW + "在手，劍如流水，見風就長，劍美，劍法更美，美的像一個受寵若驚，\n"
            +HIW + "那一劍不是勾魂，也不是奪魄，而是一種魂盡天涯無飄泊，轉成了電的速度，雷的震愕，向$n" + HIW + "刺來！" + NOR,
               "dodge"  :        -15,
               "move"   :        -30,
               "damage" :        180,
               "parry"  :          5,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "驚嚇劍傷",
]),
//2
([ "action" :NOR + "                                  " + HBRED + "==那一劍的浪漫==" + NOR + "\n" + NOR+
             HIW + "$w" + HIW + "迎著冷月閃出愛情一般奇詭的冷芒，在冷月下浮沉了幾道寒芒，就像淒美得可以讓人\n"
            +HIW + "一口逼進的鯨吞，有如劍花般的寂莫，繚繞在$n" + HIW + "腦裡，迂迴在$n" + HIW + "心中，直攻入愁腸！" + NOR,
               "dodge"  :         20,
               "move"   :          0,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "愁怨劍傷",
]),
//3
([ "action" :NOR + "                                  " + HBRED + "==那一劍的淒然==" + NOR + "\n" + NOR+
             HIW + "$N心靜，手穩，悶哼一聲，手中$w" + HIW + "已刺出點點銀光，像一記無意的顧盼，刻意的雷極，\n"
            +HIW + "直擊$n，劍影如深深的恨，淺淺的夢，又似歲月的淚\痕！" + NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "心碎劍傷",
]),
//4
([ "action" :NOR + "                                  " + HBRED + "==那一劍的風情==" + NOR + "\n" + NOR+
             HIW + "$N這一劍的意境，無法用言語、用圖畫、用文字去形容，既不是快、亦不是奇、也不是絕、更不只是優美，\n"
            +HIW + "而是一種只應天上有，不應世間無的劍法，$n" + HIW + "驚愣的臉容在剎那間凝結！" + NOR,
               "dodge"  :         10,
               "move"   :         30,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: lockman :),
               "damage_type":  "莫名劍傷",
]),
//5
([ "action" :NOR + "                                  " + HBRED + "==那一劍的燦爛==" + NOR + "\n" + NOR+
             HIW + "$N嘯聲清亮，如鷹戾九宵，劍影交錯似如漩渦，又似湖中的漣漪，綿綿不絕，那銀芒就宛如夜星般的\n"
            +HIW + "令$n" + HIW + "不知該如何閃避，剎那間濺起了淡淡血光！" + NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: four_kill :),
               "damage_type":  "點點刺傷",
]),
//6
([ "action" :NOR + "                                  " + HBRED + "==那一劍的瀟洒==" + NOR + "\n" + NOR+
             HIW + "$N手中的$w" + HIW + "發出一道淡淡的藍光，淡的就像是黎明初現的那一抹曙色，來勢奇快，無影無形，\n"
            +HIW + "劍氣激盪，凌厲無比，令$n" + HIW + "難以抵擋，劍氣的鋒芒砍入肌骨！" + NOR,
               "dodge"  :        -20,
               "move"   :        -20,
               "damage" :        200,
               "parry"  :         20,
               "force"  :        200,
               "post_action":  (: power_slash :),
               "damage_type":  "劍氣刺傷",
]),
//7
([ "action" :NOR + "                                  " + HBRED + "==那一劍的哀愁==" + NOR + "\n" + NOR+
             HIW + "滄涼古老的劍聲，就彷彿和晨霧從虛無縹緲中散發出來的，縹緲的劍聲，像是遠方伊人的呼喚，\n"
            +HIW + "又像是在訴說一種說不出的哀愁，無可奈何的哀愁，卻又帶著說不出的寧靜！" + NOR,
               "dodge"  :        -10,
               "move"   :        -10,
               "damage" :        200,
               "parry"  :        -70,
               "force"  :        500,
               "post_action":  (: seven :),
               "damage_type":  "愁怨劍傷",
]),
//8
([ "action" :NOR + "                                  " + HBRED + "==那一劍的寂寞==" + NOR + "\n" + NOR+
             HIW + "淒美的劍光讓$n" + HIW + "心神糾纏化成鬱結，不哭一聲，不訴一聲，就把$n" + HIW + "的記憶導引向要忘了的那一段浮沉，\n"
            +HIW + "把白晝換上黃昏的寂寞，讓$n" + HIW + "逐漸失去自己的感覺，而在歲月的微光裡平添害怕，而且不甚快樂！" + NOR,
               "dodge"  :          0,
               "move"   :          0,
               "damage" :        250,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "憂怨劍傷",
]),
//以下是相思碎夢刀訣
//9
(["action" :HIC + "$N右手執$w" + HIC + "，形如流水，使出" + HIY + "『悠美如夢』" + HIC + "，刀光淡淡，\n"
               "如遠山的望眉，夕照的依稀，刀光閃在$n的眸裡，$n冷不防地受到猛烈的攻擊！" + NOR,
               "dodge" :           0,
               "parry" :           0,
               "damage":         150,
               "force" :         150,
               "post_action":  (: two :),
               "damage_type" : "憂柔刀傷",
]),
//10
(["action" :HIC + "$N右手反轉，$w" + HIC + "自鞘中翻覆而握，使出" + HIY + "『輕盈若詩』" + HIC + "，\n"
               "刀光像一首動人的詩，輕的像一陣微風，柔的像一抹月色，$n招架不及，\n"
               "著了一道嚴重的刀傷！" + NOR,
              "dodge" :          10,
              "parry" :          10,
              "damage":         200,
              "force" :         150,
              "post_action":  (: two :),
              "damage_type" : "憂柔刀傷",
]),
//11
(["action" :HIC + "$N隨嘆息而出刀，使出" + HIY + "『夢裡花落』" + HIC + "，悠遠的刀光去勢之疾，快逾電光，\n"+
               "閃電般斬向$n的腹中，$n臉上的表情，正如心肺被撕裂的痛楚！" + NOR,
              "dodge" :          20,
              "parry" :          20,
              "damage":         220,
              "force" :         200,
              "post_action":  (: dream :),
              "damage_type" : "相思之傷",
]),
//12
(["action" :HIC + "$N想也不想，亮出了手上的$w" + HIC + "，使出" + HIY + "『細雨黃昏』" + HIC + "，刀光驚豔般\n"
               "的亮起，如流星自長空劃過，$n感到無可抗拒的震怖，跌入嗜血的刀網中！" + NOR,
              "dodge" :          30,
              "parry" :          30,
              "damage":         240,
              "force" :         240,
              "post_action":  (: dream :),
              "damage_type" : "相思之傷",
]),
//13
(["action" :HIC + "$N突然衝了出去，刀光綽約，像一抹夕暉，一場細雨，驚豔一撇" + HIY + "『飛花逐月』" + HIC + "，\n"+
               "$n看見了如彩色一般的夢，刀過處，黑裡濺出厲紅，帶出了殘酷的現實！" + NOR,
              "dodge" :          40,
              "parry" :          40,
              "damage":         300,
              "force" :         250,
              "post_action":  (: heartkill :),
              "damage_type" : "憂柔刀傷",
]),
//14
(["action" :HIC + "$N輕彈刀鋒，震起彷似一種相見時喜悅的輕顫" + HIY + "『秋風趕塵』" + HIC + "，一刀揮出像一道歲月的夢痕，\n"+
               "刀落時還帶著些許\美麗的風華，$n沒有退路，\n無法閃躲，不能招架！" + NOR,
              "dodge" :          30,
              "parry" :          30,
              "damage":         300,
              "force" :         300,
              "post_action":  (: disenforce :),
              "damage_type" : "哀思刀傷",
]),
//15
(["action" :HIC + "$N拔刀作龍吟，比琴鳴箏響還動聽， 帶著微微的香氣和呻吟，" + HIY + "『相思若夢』" + HIC + "刀光紛飛，\n"+
               "似千道銀雨，森寒的刀勁猶如一張天羅地網，$n的去路已被封鎖、切斷！" + NOR,
              "dodge" :          20,
              "parry" :          20,
              "damage":         350,
              "force" :         400,
              "post_action":  (: dream :),
              "damage_type" : "哀怨刀傷",
]),
//16
(["action" :HIC + "$N使出" + HIY + "『慾斷魂飛』" + HIC + "，$w" + HIC + "陡然而起，瞬然而止，刀光漾起一種淒美的顏色，\n"+
               "在晨曦的長空中，化作一道璨耀精虹，一縷\急風，並透了刀氣與刀風，急取$n！" + NOR,
             "dodge" :            0,
             "parry" :            0,
             "damage":          400,
             "force" :          500,
             "post_action":  (: fast :),
             "damage_type" : "憂怨刀傷",
]),
});


mapping query_action(object me,object weapon)
{
        mapping do_action;
        string actionn;
        int skill_level,me_sk,en_sk,bell,limit,mk,i,j,kee;
        object *enemy ,wea,weaponn;
        enemy = me->query_enemy();
        bell = me->query("bellicosity",1);
        weaponn=me->query_temp("weapon");
        wea = me->query_temp("secondary_weapon");
        skill_level = me->query_skill("love-sword", 1);
        limit= skill_level/10;
        mk = (int)me->query("MKS",1);
        me_sk = random((int)me->query("combat_exp",1)/200000) + (int)me->query_cor() + (int)me->query_cps() + (int)me->query_skill("love-sword",1)/7;

 if( bell<50 && mk<8500 && random(4)==0 && me->query("sen") > 50 && weapon->query("skill_type")=="sword" && wea->query("skill_type")=="blade" && me->query_skill_mapped("parry")=="dream-blade" && me->query_skill_mapped("sword")=="love-sword" && skill_level
 >= 100)
   {
    for(i=0; i<sizeof(enemy); i++)
     {
en_sk = random((int)enemy[i]->query("combat_exp",1)/200000) + (int)enemy[i]->query_skill("dodge",1)/5+ (int)enemy[i]->query_skill("parry",1)/5 + random(10);
    for(j=0; j<limit+4; j++) {
        do_action = action[random(16)];
        actionn = "\n";
        actionn += do_action["action"];
        if( weaponn=me->query_temp("weapon") )
        actionn = replace_string(actionn, "$w", weaponn->name());
        message_vision(actionn, me, enemy[i]);
        if( random(me_sk)+20 >= random(en_sk) )
        {
        kee = enemy[i]->query("eff_kee");
        enemy[i]->receive_wound("kee", ( random((int)kee/30)+100 ) );
        kee = enemy[i]->query("kee");
        enemy[i]->receive_damage("kee", kee/20);
        message_vision(HIG + "\n夢裡閃過快刀，風裡掠過長劍，刀劍聯手，勁碎裂，人破滅．．\n" + NOR, enemy[i]);
        COMBAT_D->report_status(enemy[i]);
        }
        else message_vision(HIB + "\n$N明心見性，左閃快刀，右避長劍，有驚無險．．\n" + NOR, enemy[i]);
       }
       }
     if( random(me->query_cps()) < 3 )
       {
        me->add("sen", -30);
        message_vision(HIM + "\n$N突然旋舞出極淒豔的殺氣，刀劍合壁攻勢因而瓦解．．\n" + NOR, me ,enemy[i]);
        me->start_busy(1);
       }
     return action[random(sizeof(action))];
   }
        //刀劍合壁,enable parry dream-blade,enable sword love-sword
        if ( wea && wea->query("skill_type")=="blade" && me->query_skill_mapped("parry")=="dream-blade" && me->query_skill_mapped("sword")=="love-sword" && skill_level == 120)
        {
                    if(me->query("bellicosity") > 400 && mk > 10000)
                      return action[random(10)];
               else if(me->query("bellicosity") > 300 && mk > 9000)
                      return action[random(12)];
               else if(me->query("bellicosity") > 200 && mk > 8500)
                      return action[random(14)];
               else
                      return action[random(16)];
        }

       //只有使用love-sword的情形下
       if (limit < 2 )
                return action[0];
       else if (limit < 4 )
                return action[random(2)];
       else if (limit < 6 )
                return action[random(3)];
       else if (limit < 7 )
                return action[random(4)];
       else if (limit < 9 )
                return action[random(5)];
       else if (limit < 10 )
                return action[random(6)];
       else if (limit < 11 )
                return action[random(7)];
       else
                return action[random(8)];

}

//殺人數以在8000做基準,8000-10000才會強,10000以上會有很多副攻出不來,或是威力不強
//情劍的一劍七色七連擊
void seven(object me,object victim,object weapon,int damage)
{
  int i,mk,da;
  mk = (int)me->query("MKS",1);
  weapon=me->query_temp("weapon");
  if(mk < 10000 ) { da = 130; }
  else { da=100; }
 if( me->query("bellicosity",1) < 200 && mk<10000)
 {
    message_vision(HIW + "\n      $N手中握的"+weapon->name()+"" + HIW + "彷彿是殺人的利器，精華，致命的一招，這一招不但詭異．毒辣．準確\n\n" + HIW + "        $n所有的動作，竟在這一劍使出時忽然間全部停頓，然後蒼穹間就濺出了一片花雨\n\n" + HIW + "                    滿天的劍影，滿天的血花，劍花又轉，由慢轉快，由純變混\n\n" + HIW + "               忽然又化作一道匹練般的彩紅，七色彩紅，七劍，多采多姿，千變萬化\n\n" + NOR,me,victim);
    for(i=1;i<=7;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf(HIR + "                       --<<紅>>劍意有如風不定．傷遮流景．落紅應滿徑--\n" + NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(YEL + "                       --<<橙>>劍意有如拋棄久．惆悵依舊．鏡裏人顏瘦--\n" + NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY + "                       --<<黃>>劍意有如雨初歇．曉風殘月．更與何人說--\n" + NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIG + "                       --<<綠>>劍意有如黯天際．望極春愁．強樂還無味--\n" + NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIB + "                       --<<藍>>劍意有如亂蟬嘶．酒徒蕭索．不似去年時--\n" + NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(CYN + "                       --<<靛>>劍意有如照無眠．悲歡離合．何似在人間--\n" + NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(MAG + "                       --<<紫>>劍意有如追憶思．酒入愁腸．化作相思淚\--\n" + NOR),me,victim);
     break;
     }
     if( me->query_skill("love-sword",1) > random(30)+100)
     {
message_vision(sprintf(HIC + "$n被$N的七色劍意所困，全身上下傷痕累累！\n" + NOR),me,victim);
          victim->receive_wound("kee",da,me);
          COMBAT_D->report_status(victim,1);

     }
     else
     {
           message_vision(sprintf(WHT + "$n"+WHT + "心如止水，看清了$N"+WHT + "的劍勢！\n" + NOR),me,victim);
     }
   }
 }
}


//busy對手,兼有攻擊之功能
void lockman(object me,object victim,object weapon,int damage)
{
        int mk,mecor,victimcor;
        mk = (int)me->query("MKS",1);
        mecor = me->query_cor() + me->query_cps() + me->query("combat_exp")/100000 ;
        victimcor = victim->query_cor() + victim->query_cps() + victim->query("combat_exp")/100000 ;
        if(!me->query_temp("lockman") && me->query("force") > 50 && mk < 10000 && damage > 0)
        {
               me->set_temp("lockman",1);
               me->add("force",-50);
               victim->start_busy(2);
               if( random(mecor) >= random(victimcor))
                {
                   message_vision(CYN + "劍意已奪去$n" + CYN + "的心志，使$n" + CYN + "遁入記憶的愴涼裡，悲憤的不惜向自己的夢中殺去．．\n" + NOR , me , victim );
                   victim->receive_damage("kee",3*me->query_skill("love-sword",1),me);
                   victim->receive_damage("sen",1*(victim->query("max_sen")/10));
                   victim->receive_damage("gin",1*(victim->query("max_gin")/10));
                   if (damage <= 0)
                   COMBAT_D->report_status(victim, 1);
                }
                else{
                        message_vision(sprintf(CYN + "劍光奪麗，劍意絕情，$n" + CYN + "覺得劍花已交織成一張殺意的網！\n" + NOR),me,victim);
                }
         }
         else{
                 me->delete_temp("lockman");
         }

}


//殺氣小於200,殺人數小於10000,機率約6成,傷害約480
void four_kill(object me,object victim,object weapon,int damage)
{
 int bell,mk;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 damage= (int)(me->query_skill("love-sword", 1));
 if(!me->query_temp("four_kill"))
 {
  if( random(100) < 60 && mk < 10000 && bell < 200  && damage>0)
   {
me->set_temp("four_kill",1);
message_vision("\n
                             " + HIG + "§情真愛又真．快樂是人生§" + NOR + "\n" + NOR,me,victim);
             victim->receive_damage("kee",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             " + HIB + "§情真愛半分．半生空遺恨§" + NOR + "\n" + NOR,me,victim);
             victim->receive_damage("kee",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             " + HIR + "§情愛沒緣份．一生不饒人§" + NOR + "\n" + NOR,me,victim);
             victim->receive_damage("kee",1*damage);
             COMBAT_D->report_status(victim);
message_vision("
                             " + HIC + "§情愛寂寞人．寂寞是人生§" + NOR + "\n" + NOR,me,victim);
             victim->receive_damage("kee",1*damage);
             victim->start_busy(random(2)+1);
             COMBAT_D->report_status(victim);
             call_out("five_kill", 1 ,me);
   }
 }
  me->delete_temp("four_kill");
}

//連接四殺,殺氣須小於50威力才會大,機率約55%
int five_kill(object me,object victim,object weapon,int damage)
{
 int bell = me->query("bellicosity");
 weapon=me->query_temp("weapon");
   message_vision("\n
  " + HIY + "       $N的人與劍已開始有了動作，一種極緩慢，極優美的動作，就像是風那麼自然\n
  " + HIY + "                    $N的瞳孔在收縮，"+weapon->name()+"" + HIY + "已慢慢的刺了出來\n
  " + HIY + "             從最不可思議的部位刺了出來，刺出時忽然又有了最不可思議的變化\n
  " + HIY + "         世上根本沒有人能破這一劍，絕對沒有任何人能誰想去破這一劍，就是去送死\n\n" + NOR,me,victim);
 if(bell < 50 && random(10)>4)
  {

   message_vision(HIR + "              血花耀眼又燦爛，燦爛的婉如流星，流星一現即逝，血花也很快的灑下\n" + NOR, me);
        victim->add("force",-1*victim->query("max_force")/5);
        victim->receive_damage("kee",1*(victim->query("max_kee")/5));
        victim->receive_damage("sen",1*(victim->query("max_sen")/5));
        victim->receive_damage("gin",1*(victim->query("max_gin")/5));
        victim->start_busy(2);
        me->add("force",-1*(me->query("force")/10));
  }
   else
  {
   message_vision(HIR + "              血花耀眼又燦爛，燦爛的婉如流星，流星一現即逝，血花也很快的灑下\n" + NOR, me);
        victim->add("force",-1*victim->query("max_force")/10);
        victim->receive_damage("kee",1*(victim->query("max_kee")/10));
        victim->receive_damage("sen",1*(victim->query("max_sen")/10));
        victim->receive_damage("gin",1*(victim->query("max_gin")/10));
        victim->start_busy(1);
        me->add("force",-1*(me->query("force")/10));
  }
}

void lovekill(object me,object victim,object weapon,int damage)
{
 int bell,mk,skillb;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 skillb = (int)me->query_skill("love-sword",1);
if(!me->query_temp("lovekill"))
 {
 if( random(100) < 60 && mk < 9000 && bell < 100 && damage>0)
   {

message_vision("


" + HIW + "                        " + BLINK + "『 挽留天涯挽留人．挽留歲月挽留你 』" + NOR + "

" + HIY + "--在天願做比翼鳥．在地願為連理枝--" + NOR + "
" + HIR + "                                       劍意縱橫，分影倏忽，彷彿斬出了歲月驚心\n" + NOR,me,victim);
             victim->receive_damage("kee",skillb);
             COMBAT_D->report_status(victim);

message_vision("

" + HIY + "--兩情若在長久時．又豈在朝朝暮暮--" + NOR + "
" + HIR + "                                       平凡一劍，陷溺迷惘，彷彿帶出了歲月癡情\n" + NOR,me,victim);
             victim->receive_damage("kee",skillb);
             COMBAT_D->report_status(victim);

message_vision("

" + HIY + "--天涯地角有窮時．只有相思無盡處--" + NOR + "
" + HIR + "                                       劍如彩雲，燦爛奪目，彷彿舞出了歲月華彩\n" + NOR,me,victim);
             victim->receive_damage("kee",skillb);
             COMBAT_D->report_status(victim);

message_vision("

" + HIY + "--衣帶漸寬終不悔．為伊消得人憔悴--" + NOR + "
" + HIR + "                                       劍光閃爍，左右飄盪，彷彿動出了歲月無情\n" + NOR,me,victim);
             victim->receive_damage("kee",skillb);
             COMBAT_D->report_status(victim);

message_vision("

" + HIY + "--無情不似多情苦．一寸還成千萬縷\--" + NOR + "
" + HIR + "                                       劍意孤獨，灰飛煙滅，彷彿幻出了歲月無奈\n" + NOR,me,victim);
             victim->receive_damage("kee",skillb);
             COMBAT_D->report_status(victim);

message_vision("

" + HIY + "--此情可待成追憶．只是當時已惘然--" + NOR + "
" + HIR + "                                       劍光一道，奪人心魄，彷彿照出了歲月光華\n" + NOR,me,victim);
             victim->receive_damage("kee",2*skillb);
             victim->start_busy(random(2));
             COMBAT_D->report_status(victim);
   }
 }
   me->delete_temp("lovekill");
}


//減對手最大氣的20%
void power_slash(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j,bell;
 bell = me->query("bellicosity");
 damage = victim->query("eff_kee")/20;
 env = environment(me);
 enemy=me->query_enemy();
 i=sizeof(enemy);
 for(j=0;j < i;j++){
 victim=enemy[j];
    if( env == environment(victim) && bell < 100)
    {
     victim->receive_wound("kee", damage);
     switch(random(4)+1)
    {
     case 1 :
     message_vision(sprintf("\n                               " + HBCYN + "．．此情此景成追憶．．\n" + NOR),me,victim);
     message_vision(sprintf(HIW + "這麼空虛的一劍，不但是刺向$n，還似忘情過去，刺向未來，而且還刺至虛無的任一處．． \n" + NOR),me,victim);
     break;
     case 2 :
     message_vision(sprintf("\n                               " + HBWHT + "．．上天不負有心人．．\n" + NOR),me,victim);
     message_vision(sprintf(HIW + "半空劍光化作電光，霹靂擊下，劍意切入了$n中，捲入了劍氣，劍光一閃而歿\．． \n" + NOR),me,victim);
     break;
     case 3 :
     message_vision(sprintf("\n                               " + HBMAG + "．．多情自古空餘恨．．\n" + NOR),me,victim);
     message_vision(sprintf(HIW + "一片紫色劍光彷若海浪般捲向$n，$n眼裡沒有痛苦，沒有悔意，甚至沒有一點表情．．\n" + NOR),me,victim);
     break;
     case 4 :
     message_vision(sprintf("\n                               " + HBGRN + "．．情到深處無怨由．．\n" + NOR),me,victim);
     message_vision(sprintf(HIW + "這一劍之勢令$n無法閃躲，就像命宮裡的一顆魔星，八字裡注定了那麼一劍攔在命運裡．．\n" + NOR),me,victim);
     break;
    }
     COMBAT_D->report_status(victim);
    }
  }
}





//.............................................................
//dream-dest和fire-dance在刀劍合壁時以機率判斷交互出來
void dream(object me,object victim,object weapon,int damage)
{
     int mk,damagea,damage1,bell,sena,senb;
     mk = (int)me->query("MKS",1);
     if(mk < 10000)  {damagea = mk/10;  }     //mk<10000  ,威力約在800-990
     else { damagea = mk/50; }                //mk>10000  ,威力約在200-600(mk=30000)
                                              //殺人數越少,威力才會強
     damage1= random(damagea)+damagea;
     bell = me->query("bellicosity",1);
     sena = victim->query("max_sen");
     senb = sena/10;
  if( bell<100 && me->query_skill_mapped("sword") == "love-sword"  && me->query_skill_mapped("parry") == "dream-blade" && damage>0 )
   {
    if(random(100)>50)
     {
       message_vision(HIW + "\n
         $N右手自左腋出手一刀，刀光‧一閃‧一閃的刀光‧刀上藍燄大盛！\n
        " + HIW + "天地間飄曳起一道幽幽藍光，似真似幻，如沉靜的月光投入深邃的大海 \n
               " + HIW + "這一刀，極快、極速、極簡單、看去極平凡無奇‧‧‧ \n
               " + HIW + "然而卻是“相思碎夢”一千零一式中所有的精華和殺招！\n
                           " + HIW + "『" + HIR + "舞刀‧捲塵‧風行斬" + HIW + "』 \n\n" + NOR, me);

              me->add("force",-random(300));
              victim->receive_damage("kee",1*damage1);
              victim->receive_damage("sen",senb);
              COMBAT_D->report_status(victim);
      }
      else
      {
        message_vision(HIW + "\n
           一種乍看令人心動﹐細看足以讓人心血賁動的紅光﹐自刀身透了出來\n
                    " + HIW + "血紅般的刀氣有如太陽西下般撩繞在$n的周圍\n
              " + HIW + "$n只覺得又快、又奇、又絕、驚豔、瀟灑、惆悵、不可一世\n
                                  " + HIW + "『" + HIC + "烽火紅塵路" + HIW + "』\n" + NOR,me,victim);

        message_vision(HBRED + "\n$N的烽火刀氣讓$n亂了方寸，迷失在烽火紅塵之中﹗\n" + NOR,me,victim);
        victim->start_busy(random(4)+1);
        victim->receive_damage("kee",1*damagea);
      }
   }
}


//相思碎夢刀訣的八連擊
void heartkill(object me,object victim,object weapon,int damage)
{
  int i;
  message_vision(HIC + "\n\n\t只見$N的身形隨著刀式一變，刀身閃出無數耀眼的光芒，震出了一片茫茫的刀幕\n\n" + HIW + "\t～～" + BLINK + "" + HIR + "   忘棄紅塵．相思八律  " + NOR + "" + HIW + "  ～～\n\n" + NOR,me,victim);
    for(i=1;i<=8;i++)
  {
    switch(i)
     {
     case 1:
message_vision(sprintf(HIY + "$N心如刀割，黯然神傷，使出" + HIR + "忘棄紅塵" + HIW + "之"+NOR+""+RED+"「傷心律」"+NOR+""+HIY+"，刀勢如亂麻般攻向$n！\n" + NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIY + "$N心煩意亂，念念不忘，使出" + HIR + "忘棄紅塵" + HIW + "之"+NOR+""+GRN+"「扣心弦」"+NOR+""+HIY+"，刀勢如惋傷般緊扣$n！\n" + NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY + "$N心力交悴，悵然若失，使出" + HIR + "忘棄紅塵" + HIW + "之" + YEL + "「碎心聲」"+NOR+""+HIY+"，刀勢如悽愴般席捲$n！\n" + NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIY + "$N心不在焉，神不守舍，使出" + HIR + "忘棄紅塵" + HIW + "之" + MAG + "「失心樂」"+NOR+""+HIY+"，刀勢如忘情般幻惑$n！\n" + NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIY + "$N心不由主，失魂落魄，使出" + HIR + "忘棄紅塵" + HIW + "之"+NOR+""+CYN+"「惑心音」"+NOR+""+HIY+"，刀勢如鬼魅般迷惑$n！\n" + NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(HIY + "$N心如死灰，情至義盡，使出" + HIR + "忘棄紅塵" + HIW + "之" + HIB + "「葬心曲」"+NOR+""+HIY+"，刀勢如怒濤般湧向$n！\n" + NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(HIY + "$N心有餘悸，恨海難填，使出" + HIR + "忘棄紅塵" + HIW + "之" + HIC + "「餘心韻」"+NOR+""+HIY+"，刀勢如悲涼般牽引$n！\n" + NOR),me,victim);
     break;
     case 8:
message_vision(sprintf(HIY + "$N心凝形釋，平心靜氣，使出" + HIR + "忘棄紅塵" + HIW + "之" + HIW + "「定心調」"+NOR+""+HIY+"，刀勢如無形般直取$n。\n" + NOR),me,victim);
     break;
     }
     if( me->query_skill("dream-blade",1)> random(60)+100)
     {
message_vision(sprintf(MAG + "結果被$N確確實實的命中要害，$n身上立即多了一道無情的傷痕！\n" + NOR),me,victim);
          victim->receive_wound("kee",90,me);

          COMBAT_D->report_status(victim,1);

     }
     else
     {
           message_vision(sprintf(HIB + "結果$N的攻擊被$n避了開來！\n" + NOR),me,victim);
     }
   }
}


//相思碎夢刀訣的奧義三連擊
void fast(object me,object victim,object weapon,int damage)
{
    int i;

    if( userp(me) && !me->query("yi/dream") ) return;
    if(( (int)me->query("force") > 300 ) && me->query("force_factor") && me->query("bellicosity") < 200  && damage>0)
    {
       message_vision(CYN + "\n\n\t$N笑意微泛，眼裡彷彿出現一道陰影，一瞬而過，刀光一閃。。。\n\n" + HIW + "\t～～" + BLINK + "" + HIR + "  碎夢奧義．迴天夢舞" + NOR + "" + HIW + "  ～～\n\n" + NOR,me,victim);
       for(i=1;i<=3;i++)
       {
         switch(i)
         {
            case 1:
            message_vision(HIY + "\n＝＝" + HIR + "醉   夢" + HIY + "＝＝\n" + NOR,me,victim);
            message_vision(HIW + "刀盪刀風，刀美如夢，彩色繽紛，絕美的刀光，如同驚豔遇著風華，\n空間為奇彩所充滿，"
                                       +"五彩光華，如癡如醉，似一連串的迷夢在空中閃現，\n迷絢於一連串夢一般的幻像裏。。\n" + NOR,me,victim);
             break;

            case 2:
            message_vision(HIY + "\n＝＝" + HIR + "驚   夢" + HIY + "＝＝\n" + NOR,me,victim);
            message_vision(HIW + "刀光綽約，騰起一陣凌厲而且豔麗的殺意，刀氣如浪分濤裂似排山倒海的擊出，\n"+
                                         "刀光散開，發出奪目的光彩，血似的鮮紅色，悽豔亮烈，驚醒彩色的夢。。\n" + NOR,me,victim);
             break;

            case 3:
            message_vision(HIY + "\n＝＝" + HIR + "碎   夢" + HIY + "＝＝\n" + NOR,me,victim);
            message_vision(HIW + "天雷忽起，大地浮沉，刀光摒出一道道的強光，裂蒼天而出，震蒼生而鳴，狂飆忽起，\n"+
                                        " 彷彿潛伏地底的怒龍，裂夢而起，上七重天，昇九萬里，勢所無匹。。\n" + NOR,me,victim);
             break;
           }
           if( me->query_skill("dream-blade",1) > random(60)+100)
           {
                  message_vision(MAG + "\n$N的刀法舞的如夢似幻，$n身上著了一道深可見骨的傷痕卻不自知！\n" + NOR,me,victim);
                  victim->receive_wound("kee",400,me);
                  me->add("force",-50);
                  if(i != 3)
                  COMBAT_D->report_status(victim,1);
                  else if( damage <=0 )
                  COMBAT_D->report_status(victim,1);
           }
            else
            {
                  message_vision(HIB + "$n看清了$N的攻勢，不徐不疾的避了開來！\n" + NOR,me,victim);
            }
        }
    }
}

void two(object me,object victim,object weapon,int damage)
{
     int bell,sk,mk,mk1,i;
     bell = me->query("bellicosity",1);
     sk= me->query_skill("love-sword", 1);
     mk = me->query("MKS");
     if(mk<8500)
      {damage = 3*sk;
      mk1=5;}
     else if(mk<9000)
      {damage = 3*sk;
      mk1=4;}
     else if(mk<9500)
      {damage = 3*sk;
      mk1=3;}
     else if(mk<10000)
      {damage = 3*sk;
      mk1=2;}
     else
      {damage = 3*sk;
      mk1=1;}

if( bell<100 && me->query_skill_mapped("sword") == "love-sword"  && me->query_skill_mapped("parry") == "dream-blade"  && damage>0)
 {
   message_vision(HIW + "\n       刀像一陣風，劍像一縷\煙，來得就像是流水那麼自然，不但有了生命，也有了靈氣，更有了殺氣\n\n" + HIW + "                          美麗．光華在閃動．變幻．高高在上．輕雲飄忽\n\n" + HIW + "                   $n只覺得這道光華彷彿就在自己眉宇間，又彷彿在虛無縹緲間\n\n" + HIW + "                   它的變化，幾乎已超越了人類能力的極限，幾乎已令人無法相信\n\n" + NOR,me,victim);
       for(i=0;i<=mk1;i++)
         {
          victim->receive_damage("kee",damage);
          COMBAT_D->report_status(victim);
         }
 }
}


//打掉對手的enforce
void disenforce(object me, object victim, object weapon, int damage)
{
        int skillb = (int)me->query_skill("love-sword",1);
        int me_gin = me->query("max_gin")/5;
        int me_kee = me->query("max_kee")/10;
        int me_sen = me->query("max_sen")/5;
        int victimenf = victim->query("force_factor");
        if( !me->query_temp("disenforce"))
        {
          if(skillb >= 100 && me->query("bellicosity",1)<30 && damage>0 && victimenf > 0)
            {
                message_vision(HIR + "\n
             $N的刀劍本來是平淡毫無變化，卻忽然間，劍尖起了一種很奇異的震動\n\n" + HIR + "              刀勢本來很快，就在這時忽然慢了下來，很慢，雖然慢，卻還是在變\n\n" + HIR + "                        光芒在現，劍鋒迥異，刀光如幻，詭異的閃動\n\n" + HIR + "                $n覺得這份詭異彷彿就在自己眉睫間，又彷彿在虛無的縹緲間\n\n" + NOR + "            " + HBBLU + "刀光劍意已侵入$n神志，粉碎了$n的鬥志，讓$n儘往回憶的傷悲處走\n" + NOR, me, victim);
                me->set_temp("disenforce",1);
                victim->set("force_factor", 0);
                me->receive_wound("gin",me_gin,me);
                me->receive_wound("kee",me_kee,me);
                me->receive_wound("sen",me_sen,me);
            }else{ message_vision(NOR + "\n" + NOR,me,victim);}
        }
        else {me->delete_temp("disenforce");}
}

int valid_learn(object me)
{
        int bell, skill;
        object ob;
        bell = me->query("bellicosity");
        skill =me->query_skill("love-sword", 1);
        if(me->query("get-2skill-s") != 1 )         //解love-sword的mark
        {
         tell_object(me, HIY + "王小石說道：你我既無師徒之實，怎麼叫我傳授劍法給你！\n" + NOR);
         return 0;
         }
         else
         {
         if( me->query("family/master_name") != "王小石" )
         {
                tell_object(me, HIY + "王小石說道：你我既無師徒之實，怎麼叫我傳授劍法給你！\n" + NOR);
                return 0;
         }
         if((int)me->query("max_force") < 2000)
         {
                tell_object(me, HIY + "王小石說道：你的內力修為似乎不足以修練「情劍」！\n" + NOR);
                return 0;
         }
         if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
         {
                tell_object(me, HIY + "王小石說道：沒拿劍怎麼練劍法啊！\n" + NOR);
                return 0;
         }
         if( (me->query("potential") - me->query("learned_points")) < 5 ) {
                tell_object(me, "你的潛能不到五點, 無法練此刀法。\n");
                return 0;
         }
         if( bell > 100 )
         {
                tell_object(me, HIY + "王小石說道：你心存殺念, 怎麼能夠學習情劍呢！\n");
                return 0;
         }
        tell_object(me, HIY + "王小石說道：學此劍法需扣潛能、精、氣、神各五點。\n");
        me->add("gin", -5);
        me->add("kee", -5);
        me->add("sen", -5);
        me->add("potential", -5);
        return 1;
       }
}
int valid_enable(string usage)
{
        return usage== "sword" || usage=="parry";
}

string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}

string exert_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}
