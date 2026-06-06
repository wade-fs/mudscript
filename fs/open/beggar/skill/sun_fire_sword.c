// 連陽七訣劍法
//取代原來的迅雷劍法 && 提高解迷難度
//roger && taifar於 98/8/16

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);

int kar=this_player()->query_kar(1);
int cps=this_player()->query_cps(1);
int str=this_player()->query_str(1);
int cor=this_player()->query_cor(1);
int int1=this_player()->query_int(1);
int spi=this_player()->query_spi(1);
int sp_value;

string *parry_msg = ({
"\n而$n手中的長劍一橫，一招"HIB"『鐵鎖橫江』"NOR"勢挾千斤往前一推一送，噹的一聲碰出了點點火花反把$N手中的$w險些震飛！\n"NOR,
"\n但$n長劍一轉，順著$N的$w以一招"HIC"『順流而下』"NOR"往$N的手指削去，$N大驚失色下急忙收招回架\n",
"\n$n劍走輕靈，手中長劍忽削忽刺一連串的兵器撞擊聲後$n已將$N的快招全部化解！\n",
HIW"\n$n以快制快，$N快但$n更快，連續刺出了七七四十九劍織成一道劍網將$N的招式盡數盪開！\n"NOR,    
        });

string *unarmed_parry_msg = ({
"但是被$n格開了。\n",
"結果被$n擋開了。\n",
});

string *lan_yan = ({
HIW"$N使出烈陽第一式"HIR"『浩日初昇』"HIW"，手中的$w"HIW"快速舞動著，挾著陣陣烈風襲向四周，一時間劍氣縱橫\n"NOR,
HIW"$N手中$w"HIW"突然嗡嗡巨響，使出烈陽第二式"HIR"『烈日迫世』"HIW"，手中$w"HIW"，發出霹靂巨響刺向四周的敵人\n"NOR,
HIW"$N手中$w"HIW"急速顫動，瞬間滿天劍花閃閃，正是烈陽第三式"HIR"『千華映日』"HIW"，招如其名，只見敵人的血如落花般飛濺...\n"NOR,
HIW"$N身形急旋，使出烈陽第四式"HIR"『風沙灼日』"HIW"，只見渾燙的風捲起滾滾塵沙，令人摸不清$N在何方...\n"NOR,
HIW"$N手捏劍訣，忽然手中的$w"HIW"往天空飛去，瞬時間數道劍氣往下激射，正是烈陽第五式"HIR"『虹雲過日』\n"NOR,
HIW"$N使出烈陽第六式"HIR"『昇龍旋日』"HIW"身形猶如一條灰龍急旋而上，且散發出灼熱的氣息襲向四周，好像要一舉吞沒敵人似的\n"NOR,
HIW"$N大喝一聲，使出烈陽第七式"HIR"『烈日當空』"HIW"，一瞬間已向四周刺出了七七四十九劍!\n"NOR,
HIW"$N手中的$w"HIW"，忽劈忽刺，一招烈陽第八式，"HIR"『燄日迫雷』"HIW"使將出來，四周響起了隆隆巨響!\n"NOR,
HIW"$N手中的$w"HIW"劍芒忽然一長，使出烈陽第九式"HIR"『劃日飛電』"HIW"，只見劍芒不停的吞吐閃爍，令人眼花撩亂間$w"HIW"，已穿體而出...\n"NOR,
HIW"$N使出絕頂輕功\，一招烈陽第十式"HIR"『蔽雨熱日』"HIW"，使將出來，周圍敵人紛紛不住地倒退...\n"NOR,
HIW"$N身形一晃，手中$w"HIW"，不絕的向敵人追隨而去，正是烈陽第十一式"HIR"『斜日掛影』"HIW"，令敵人避無可避\n"NOR,
HIW"$N手中的$w"HIW"忽然變成軟軟綿綿，劍招去勢詭異莫測，正是烈陽第十二式"HIR"『陰雲掩日』"HIW"令敵人無從招架起\n"NOR,
HIW"$N手中的$w"HIW"飛射而出，使出烈陽第十三式"HIR"『刃日飛風』"HIW"，只見$w"HIW"在$N雙手真氣的控制下以極高的速度刺向周圍的敵人。\n"NOR,
HIW"$N使出烈陽第十四式"HIR"『炎日千印』"HIW"，手中的$w"HIW"忽然飛快的舞動，形成一道道幻影刺向周圍的敵人。\n"NOR,
HIW"$N手中的$w"HIW"往外一分，忽然化成成千上萬的幻影籠罩著四周的敵人，正是烈陽第十五式"HIR"『幻日流光』"HIW"，周圍敵人紛紛退卻...\n"NOR,
HIW"$N將手中的$w"HIW"舞得更急，使出烈陽第十六式"HIR"『狂日盡蝕』"HIW"，劍法快的連劍的蹤影都看不到只聽一聲慘號$n已被刺傷!。\n"NOR,
HIW"$N使出烈陽第十七式"HIR"『偽日為真』"HIW"，劍法之快，招式之辣，實已令人匪夷所思，所刺出的每一招皆令敵人受到重創\n"NOR,
});

string *shasword = ({
"$N手捏劍訣，長劍一挺，使出一招"HIC"『泉鳴芙蓉』"NOR"，姿態悠雅，頗有天上仙人下凡間之意\n",
"$N一個旋身，手中的$w在空中閃過一道光芒直刺向$n的$l，姿態瀟灑一氣呵成，正是一招"HIY"『金雁橫空』\n"NOR,
"$N左肩微沉，左手劍訣斜引，右肘一縮，使出一招"HIM"『有鳳來儀』"NOR"劍勢迅速凌厲直往$n的$l刺去\n",
"$N劍勢一改往常的飄逸絕倫，使出一招"HIW"『"HIY"玉碎仙岡"HIW"』"NOR"直削橫劈、氣勢威猛的往$n身上大力斬去\n",
"$N劍勢大開大闔，使出一招"HIC"『劈竹掃影』"NOR"狂風暴雨般的招式使$n感到難以招架\n",
"$N劍尖連劃出幾個劍花，一招"HIW"『飄雲穿雪』"NOR"如浮雲般飄逸，化成片片白雪緩緩落於$n的身上\n",
"$N將手中的$w斜引，使出一招"HIW"『峭壁斷雲』"NOR"，劍勢雄偉精奇氣勢縱橫使$n感到左支右拙難以招架\n",
"$N真氣灌於手中的$w，使出一招"HIR"『飛虹橫江』"NOR"頓時劍尖衝出半尺來長的紅色劍芒，吞吐閃爍，嗤嗤聲響處往$n疾刺而去\n",
"$N手中的$w一閃出鞘，寒芒吞吐，電閃星爍，一招"HIB"『寒芒沖霄』"NOR"劍氣化成點點寒芒往$n身上飛去\n",
"$N一聲清嘯，手中長劍抖動處數以百計的玉色光芒從$N的劍尖疾飛而出，燦爛如銀河飛濺，正是一招"HIW"『"HIY"盡傾銀河"HIW"』\n"NOR,
"$N使出仙劍派之絕招"HIG"『隔紙斷樹』"NOR"，手中的$w虛劃，$n愕然不明所以之際不知自己筋脈已被斬斷...\n",
"$N劍泛仙氣，聚精會神地使出了仙劍劍術中的最高境界"HIY"『仙傾霜天』"NOR"！劍由仙化，使劍若仙，金光閃耀下$n全身已被割傷多處...\n",
});



mapping *action = ({
//1
        ([      
                "action"     :               HIC"$N收光為暈斂剛成柔，使出了仙劍禁斷之連陽七訣第二式"HIY"『殘陽』"HIC"，瞬間身化殘影落步，劍尖分指$n$l"NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "刺傷"
        ]),
//2
        ([     
                "action"     :               HIC"$N步若游光使出仙劍禁斷之連陽七訣第四式"HIY"『暖陽』"HIC"，劍氣烘燃，一流宏大的劍壓曲地逼近$n"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "刺傷"
        ]),
//3
        ([   
                "action"     :               HIC"$N飛身高躍倏然使出了仙劍禁斷之連陽七訣第三式"HIY"『豔陽』"HIC"，劍光如浩日輝煌，筆直落在$n眉心"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                200,
                "force"      :                200,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "刺傷"
        ]),
//4
        ([  
                "action"     :               HIC"$N撫劍如靜，心若止水劍光瀲豔，仙劍禁斷之連陽七訣第五式"HIY"『冬陽』"HIC"泛起波波殺意如刃向$n繞流而去"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "割傷"
        ]),
//5
        ([ 
                "action"     :               HIC"$N手裡的$w"HIC"泛出陣陣如暮色般的劍氣，仙劍禁斷之連陽七訣第七式"HIY"『夕陽』"HIC"猶如霞光滿天盡落$n身上"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "割傷"
        ]),
//6
        ([
                "action"     :               HIC"$N峰迴路轉內勁猛然上竄使出仙劍禁斷之連陽七訣第一式"HIY"『烈陽』"HIC"，劍光如烈陽狂燄直奔$n心口"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺傷"
        ]),
//7
         ([     "action"     :               HIC"$N將$w"HIC"收鞘而入，聚精凝神使出仙劍禁斷之連陽七訣第六式"HIY"『朝陽』"HIC"，只見劍光如晨光乍現劃向$n"NOR,
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "割傷",
           ]),
});

int valid_learn(object me)
{
       if(!me->query("quest/sun_fire_sword",1)){
        tell_object(me,"你還不夠資格練連陽七訣劍法。\n");
        return 0;
                                               }

       if( !me->query_temp("weapon")){
        tell_object(me,"練連陽七訣劍法必需先拿把劍。\n");
        return 0;
                                     }
       if( (me->query("potential") - me->query("learned_points")) < 5 ) {
        tell_object(me, "你的潛能不到五點，無法練此劍法。\n");
        return 0;
                                                                         }
        me->add("potential", -5);
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="sword" || usage=="parry" );
}


mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;

 skill_level = (int)(me->query_skill("sun_fire_sword",1));
 limit= skill_level;
     
        if (limit < 15)
                return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else       
          return action[random(7)]; 
}

void sp_attack0(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
if( me->query("family/family_name")=="仙劍派"){  
//出現率 1/2*1/7=~7%

  if( random(2) == 0 && me->query("force") > 360 && !me->query_temp("conti",1)) {
  
message_vision(HIY"
就在$n被擊中的瞬間，$N心轉"HIR"『殘陽千意』"HIY"，亂步分影遮光為幻
一心千切，同一把劍，舞的卻是不同的招式，招招朝著$n的要穴竄去
\n"NOR,me,victim);
          
    for(j=0; j < 12; j++) {
       do_action = shasword[j];
       actionn = "\n";
       actionn += do_action;
     
       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\n但是$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , enemy[i]);
        enemy[i]->receive_damage("kee",40,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比劍快, 驚險地閃過了這一招。\n" , enemy[i]);
                             }
//這裡給cps等於10的ppl 機會以高exp 壓低 delay 機率
     if( random(me->query_cps()) < 8 && random(me->query("combat_exp",1)) < 900000) {
        me->add("force",-100);
        message_vision("\n$N使完"HIY"『殘陽千意』"NOR"後，由於定力或經驗不足，體內真氣一時無以為繼\n",me);
        me->start_busy(1);
                                        }
                                                          }
                                                }
 
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(str+cor)+cps+kar+spi+int1;
if( me->query("family/family_name")=="仙劍派"){
    message_vision(HIW"
劍壓流動，隨著$N的心念越發強烈，$n無從反動，完完全全
受到劍壓的控制，衍生一式"HIY"『暖陽印境』"HIW"激出的劍虹在空中不停地聚
合盤旋，剎那間!!天地變色風起雲湧，一輪暖日在空氣之間現形而生
$n被此情景所震懾，一瞬間已被吞沒於光芒之中
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value/2,me);
   COMBAT_D->report_status(victim);
                                              }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(spi+int1)+cps+kar+str+cor;
if( me->query("family/family_name")=="仙劍派"){
    message_vision(HIY"
就在同時，$N心擴天地，懷若宇宙，狂奔的戾氣瞬間平息，$N與
天地彷彿結合為一，瑞光豔麗光彩奪目，凝止住全部的的動作 
一式"HIW"『豔陽三劍--天地人』"HIY"迅如雷光落向$n
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value/2,me);
if(random(100) > 80) {
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",1);
}
   COMBAT_D->report_status(victim); 
                                              }
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
    sp_value =4*(cps+kar)+str+cor+spi+int1;
if( me->query("family/family_name")=="仙劍派"){
    message_vision(HIW"
$N內勁頓轉使出連陽唯一陰寒之招，瞬時間一股寒氣籠罩身旁，只見
劍上薄冰漸起幻成冰柱，$N愈使愈快，宛若洶湧巨浪瞬時壓力遽增霎
時四周水波雲氣變化萬千，$n瞬間分不清劍在何方, 就在遲疑之
際，$N一式"HIC"『冬陽天冰』"HIW"捲起狂霜亂雪直搗$n心口
\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value/2,me);
    COMBAT_D->report_status(victim);
                                              }
}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;
if( me->query("family/family_name")=="仙劍派"){
    message_vision(HIR"
$N趁勢翻身飛躍，斜迴劍尖，念轉靈動使出"HIW"『紅染夕陽』"HIR"，霎時
殺意狂奔，欲噬血腥無法自制，劍鼓風旋，連鎖成無數無形風刃，削
肉刮骨欲罷不能
"NOR,me,victim);

    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
                                              }  
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;
  
  force=me->query("force",1);
  enemy = me->query_enemy();
  i=random(sizeof(enemy));
  
//出現率 1/2*1/7=~7%
if( me->query("family/family_name")=="仙劍派"){
if( random(2) == 0 && me->query("force") > 510 && !me->query_temp("conti",1)) {
message_vision(HIR"
眨眼間，劍鋒泛火，火光漸如燄日逼人，$N如化祝融全身火紅
驀地一聲大喝"HIW"『烈陽十七式』"HIR"，手中長劍猶似火龍摧天，劍幻千萬火
炬只在一瞬間$n已完全火龍被吞沒
\n"NOR,me,victim);            
    for(j=0; j < 17; j++) {
       do_action = lan_yan[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision("\n但是$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , enemy[i]);
        enemy[i]->receive_damage("kee",60,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比劍快，驚險地閃過了這一招。\n" , enemy[i]);
                             }
//這裡給cps等於10的ppl 機會以高exp 壓低 delay 機率
     if( random(me->query_cps()) < 10 && random(me->query("combat_exp",1)) < 900000) {
        me->add("force",-100);
        message_vision("\n$N使完"HIR"『烈陽十七式』"NOR"後，由於定力或經驗不足，體內真氣一時無以為繼\n",me);
        me->start_busy(1);
                                        }
                                                  }
                                             }
 
}


void sp_attack6(object me, object victim, object  weapon, int damage)
{
    int i;
    sp_value =4*(str+cor+cps)+spi+int1+kar;
  if (sp_value > 250) sp_value=250;
if( me->query("family/family_name")=="仙劍派"){
    message_vision(HIY"
瞬間，$N再收劍入鞘，心凝一式"HIW"『朝陽再現』"HIY"，迴身飛旋，幾乎是
同時，長劍已離鞘直劃$n的咽喉
\n"NOR,me,victim);
   if( weapon->query("id")=="sun_fire_sword"){
    message_vision(HIY"靈劍連陽隨著『朝陽再現』這一式散發出開天潛藏的靈氣，剎那間!劍泛金光
完全照亮了暗影，如千百個太陽在$N的手中，一齊射出無與倫比的光芒，令$n根本無法
逼視\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+150,me);
    victim->start_busy(1);
if(random(100) > 70) {
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",1);
}
    COMBAT_D->report_status(victim);
                                             }
   else{
    victim->receive_wound("kee",sp_value,me);
if(random(100) > 80) {
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",1);
}
    COMBAT_D->report_status(victim);
       }
                                              }
}


string query_parry_msg(string limb)
{
 object me=this_player();
 object weapon=me->query_temp("weapon");

  if(weapon && weapon->query("skill_type")=="sword")
      return parry_msg[random(sizeof(parry_msg))];
  else 
      return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
          return CLASS_D("swordsman")+"/shasword/"+action;
}   
        
