//驚天十式
// by dhk 2000.5.5
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void kee(object me, object victim, object weapon, int damage);

mapping *action = ({

//天地雙卦....(1)
([ "action":
         "$N雙足一跨，體內真氣流轉，立即擺\出" + BLINK+HIW + "『驚天十式』" + NOR + "中的" + HIY + "『天地雙卦』" + NOR + "，其招式中蘊含天地萬化的神奇卦象\n" + NOR + "，霸道的向$n$l直逼而去﹐頗有石破天驚、飛沙走石之勢。 \n" + NOR + "                                                                     \n"
BLINK+HIY + "                                          『  天  地  雙  卦  』" + NOR + "\n" + NOR + "                                                                     ",
        "dodge": 50,
        "parry": 50,
        "damage": 2000,
        "force":  5000,
        "damage_type":  "震傷",
        "weapon": "左足右掌",
        "post_action": (: hurt :),
]),

//穿山指....(2-1)
([ "action":
         "$N勁透指尖，使出一招" + BLINK+HIW + "『驚天十式』" + NOR + "中的絕招" + HIR + "『穿山指』" + NOR + "，一道雄渾指氣直進$n$l，其破空之勢中夾帶孅\n" + NOR + "柔飄朔之勁，威力足以震破名山巨嶽。\n" + NOR + "                                                                   \n"
BLINK+HIR + "                                            『  穿  山  破  』" + NOR + "\n" + NOR + "                                                                   ",
        "dodge": 200,
        "parry": 200,
        "damage": 600,
        "force":  1000,
        "damage_type":  "刺傷",
        "weapon": "互鑲中指",
]),

//倒行沌波....(3)
([ "action":
NOR + "$N緩緩運氣上肩，雙手高舉、雙眼望天，不一會$N深深的吸一口氣，然四周忽然\n" + NOR + "旋起強烈的氣渦。正是" + BLINK+HIW + "『驚天十式』" + NOR + "中的絕招" + HIM + "『倒行沌波』" + NOR + "，行招之時四周大氣逆行\n\n"

BLINK+HIM + "                         『  倒  行  沌  波  』" + NOR + "\n\n" + HIM + "$n被倒行沌波強勁的氣壓影響下，身受真氣逆行的痛苦" + NOR + "。\n",
        "dodge": 70,
        "parry": 70,
        "damage": 840,
        "force": 7000,
        "damage_type": "滯傷",
        "weapon": "掌氣",
        "post_action": (: hurt :),
]),

//吸星訣....(4)
([ "action":
NOR + "$N身形斗轉並深深的吐出一口真氣、抬頭仰天大喝一聲\n" + NOR + "，一招" + HIG + "『" + HIY + " 吸" + HIC + " 星" + HIM + " 訣" + HIG + " 』" + NOR + "使周圍時空幻化出無數$N的身影，頓時日月失色獨天星閃耀。\n" + NOR + "待一切回歸平靜之時，只見$N身泛金色光芒，內息充盈、不吐不快。\n",
        "dodge": 100,
        "parry": 100,
        "damage": 100,
        "force": 2000,
        "damage_type": "迫傷",
        "weapon": "星光魄氣",
        "post_action": (: kee :),
]),

//日月並行....(5-1)
([ "action":
"$N雙目緩閉氣運雙眼﹐忽然睜開左眼使出" + HIB + "『日月並行』" + NOR + "中的" + HIM + "『昊日劇昇』" + NOR + "﹐一道光彩奪目的紅光脫眼而出\n"
"、電光走石般霸道地朝向$n$l而去。\n",
        "dodge": 60,
        "parry": 60,
        "damage": 1500,
        "force": 1000,
        "damage_type": "創傷",
        "weapon": "左眼真氣",
        "post_action": (: hurt :),
]),

//急吹風....(6)
([ "action":
   "$N凝氣定神，突然隨手一晃，便即使出" + BLINK+HIW + "『驚天十式』" + NOR + "中的" + BLU + "『急吹風』" + NOR + "，莫名的產生一股強勁無匹的狂風，風轉急速。" + NOR + "\n",
        "dodge": 20,
        "parry": 20,
        "damage": 100,
        "force": 1000,
        "damage_type": "鎮傷",
        "weapon": "強大氣壓",
        "post_action": (: block :),
]),

//日月並行....(5-2)
([ "action":
"$N雙目緩閉氣運雙眼﹐忽然睜開右眼使出" + HIB + "『日月並行』" + NOR + "中的" + HIC + "『玉兔奔天』" + NOR + "﹐一道光彩奪目的白光脫眼而出\n"
"、以鳳舞九天之勢地朝向$n$l而去。\n",
        "dodge": 60,
        "parry": 60,
        "damage": 1500,
        "force": 1000,
        "damage_type": "創傷",
        "weapon": "右眼真氣",
        "post_action": (: hurt :),
]),

//強力-穿山指....(2-2)
([ "action":
HIR + "$N心如止水，不動如山，內力急劇上升。忽然$N以迅雷之速，快速欺向$n" + HIR + "而\n" + HIR + "去。此時$N" + HIR + "已經在右手中指凝聚強大滿盈的真氣、力量，當來到$n" + HIR + "身旁之時" + NOR + "\n" + HIY + "使出" + BLINK+HIW + "『驚天十式』" + NOR+HIY + "中的絕招\n" + NOR + "\n"
BLINK+HIC + "                               『  " + HIR + "穿  山  指 " + HIC + " 』" + NOR + "\n" + NOR + "\n" + HIG + "勁力一吐，有如山崩地裂、破山、穿山之勢直刺$n而來。\n" + HIR + "$n被穿山指擊中，內腑受創甚深，已氣如游絲" + NOR + "。\n",
        "dodge": 10,
        "parry": 10,
        "damage": 4000,
        "force": 2400,
        "damage_type": "刺傷",
        "weapon": "互鑲中指",
]),

//怒式天芒刺....(7)
([ "action":
HIW + "$N殺念一動，臉色驟變。右手一出立即擺\出" + BLINK+HIW + "『驚天十式』" + NOR + "中的" + HIC + "『怒式天芒刺』" + NOR + "的起手式。只見$N怒氣上升，右手漸漸凝出青顏色劍芒，霎時光芒亮如白晝。\n"
"$n的眼睛被光芒所傷，閃避不及，身體已被天芒刺劍氣所重創。\n",
        "dodge": 10,
        "parry": 10,
        "damage": 1400,
        "force": 1000,
        "damage_type": "刺傷",
        "weapon": "無形劍氣",
        "post_action": (: conti :),
]),

//奧義(一)....(8)
([ "action":
HIY + "\n$N眼中精光大盛﹐大喝:\n\n" + HIW + "             『\n" + HIY + "                  天皇" + HIW + "天式" + HIC + "～" + HIM + "覆天" + HIR + "三陽" + NOR + "\n"
"                                       』\n"
"$N突然急運『" + HIY + "御天皇氣" + NOR + "』﹐氣勁滿盈﹐一個箭步﹐向$n縱身飛去\n" + NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 7000,
        "force": 7000,
        "damage_type": "創傷",
        "post_action": (: sp1 :),
]),

//奧義(二)....(9)
([ "action":
HIW + "只見$N真氣一提，霎那天際發生奇妙的變化，頓時漫天寒雪，氣溫劇降。\n\n" + HIY + "\n$N大喝一聲:\n\n" + NOR + "
                      " + GRN + "『      " + HIC + "急凍" + HIM + "梅花" + HIY + "～" + NOR+WHT + "雪裡不凋" + NOR + "      " + GRN + " 』" + NOR + "\n\n" + HIW + "$N雙掌凝聚深厚的寒勁，奮力推出掌勁所到之處，一觸即凍。一道強力梅花形冰柱真氣直撲$n而去。\n\n" + NOR + "                         ～ " + HIW + " 漫天" + HIW + " 寒雪" + HIC + "．" + HIM + "梅花" + HIW + " 不" + RED + "凋 " + HIW + " ～\n\n
                                          ▁▂▃
                                      ／￣￣▌￣╲
                                     │     ▏  ▕
                                  ▃ ｜         ▕
       " + HIC + "｜" + NOR + "                       ／▋╲╲        ／／￣╲
       " + HIC + "｜" + NOR + "                     ／  ▍  ﹀        ﹀      ╲
     " + HIC + "–" + HIY + "⊙" + HIC + "–" + NOR + "                  ｜   ▏       " + HIY + "。" + NOR + "            ｜
       " + HIC + "｜" + NOR + "                    ｜          " + HIM + "╲｜／" + NOR + "           ▌
       " + HIC + "｜" + NOR + "                     ╲       " + HIY + "。" + HIM + "─" + HIC + "●" + HIM + "─" + HIY + "。" + NOR + "       ／▎
                                ￣＞     " + HIM + "／｜╲" + NOR + "     ＜￣  ▏
          ◣                  ▁／         " + HIY + "。" + NOR + "         ╲
        ▕ ｜ ▃▄▂        ／￣︳                     ｜        " + HIC + "｜" + NOR + "
        ／  ￣￣￣￣╲▃▂╱╱￣╲        ╱╲        ╱         " + HIC + "｜" + NOR + "
      ／╱￣▉◤￣￣╲￣￣  ╲    ╲▂ˍ╱    ╲ˍˍ╱         " + HIC + "–" + HIY + "⊙" + HIC + "–" + NOR + "
    ╱╱    ▌        ￣￣￣╲▍    ▍            ▉             " + HIC + "｜" + NOR + "
            ▏                ▎    ▏             ▍            " + HIC + "｜" + NOR + "
                              ▏                   ▏



" + HIC + "$n受到這一掌掌氣所傷，體溫驟降、真氣凝滯，受傷沉重。\n" + NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 6600,
        "force": 5600,
        "damage_type": "凍傷",
        "post_action": (: sp2 :),

]),

//奧義(三)....(10)
([ "action":
HIY + "\n$N收身回步長吟道:\n\n" + NOR + "                   " + YEL + "『 " + HIC + "右開天 " + NOR+GRN + "左闢地 " + HIB + "開天闢地" + HIR + "一貫長虹" + NOR + " " + YEL + "』" + NOR + "\n\n" + HIC + "只見$N首先向天際與大地各擊出一掌，將身上剩餘的真氣宣洩而出，身於空盪之狀態。" + NOR + "\n" + GRN + "然後緊接著又見$N雙足運勁，緊緊的吸在地面上。雙手平擺\納天地之氣於一身。隨後雙\n" + HIB + "腳如神箭離弦，脫足長躍。於高空之中大喝：                                \n\n" + NOR + "                           ～" + HIM + " 一" + HIY + " 貫" + HIC + " 天" + HIG + " 長" + HIR + " 虹" + HIW + " ～\n\n" + NOR + "" + HIR + "雙掌相合直劈而下，凡劃破的空間泛出七彩般的光華，勢如落雷" + NOR + "。\n",
        "dodge": 80,
        "parry": 50,
        "damage": 8500,
        "force": 8500,
        "damage_type": "刺傷",
        "post_action": (: sp3 :),
]),
});

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( me->query("force_factor") > 10 )
        if( random(500) < me->query_skill("force")+me->query_skill("surprise-ten",1))
        {
          force = me->query_skill("sunforce");
          victim->receive_damage("kee", 7*me->query("force_factor")+2*force );
          message_vision(sprintf("" + HIB + "$N使出驚天十式中磅礡的氣勁鎮攝" + HIB + "$n的四周，" + HIB + "$n被此強大的氣勢所引動﹐看來已受到深重的內傷。\n" + NOR),me,victim);
          if(damage <=0 )
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        int force;
        if(damage > 700)
        {
          force = (int)(me->query_skill("sunforce"));
          force = random(force/3);
          victim->apply_condition("blockade",
          random( me->query_skill("sunforce")+me->query_skill("surprise-ten") )/20 );

          message_vision(sprintf("" + HIY + "$n受到驚天十式之" + HIB + "急吹風" + HIY + "的狂襲$n" + HIY + "身不由己的隨風四擺\，動彈不得。\n" + NOR),me,victim);
          victim->start_busy(6);
          COMBAT_D->report_status(victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
        int i,time = random(3);
        if( me->query("force_factor") >= 10 )//&& me->query("family/family_name") == "段家")
        {
          if( me->query_temp("conti") == 0 )
          {
            me->set_temp("conti",1);
      message_vision(sprintf("\n$N忽然頓悟驚天十式氣衝百匯、劍落天池的要訣，劍氣自然而然的隨劍而出，密如落雨!!\n"),me);
              for(i=0;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

//吸星訣--大量回復氣與內力
void kee(object me, object victim, object weapon, int damage)
{
        int force;
        if( me->query("force_factor") > 10 )
        {
          message_vision(sprintf("" + HIY + "$N身泛金色光芒，身上的傷痕漸漸消失，內息充盈、不吐不快" + NOR + "。\n"),me);
          me->add("kee",2000);
          me->add("force",4000);
          me->start_busy(1);
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i,vic_kee;
vic_kee = victim->query("kee")/500; //kee為比例計算
if(me->query("force") > 2000 && me->query("force_factor"))
{
  for(i=1;i<=9;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$N會意了" + HIW + "『天皇天式』中" + HIR + "『旭日東昇，覆天極陽』" + NOR + "的真意﹐向$n當頭斬下!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + HIG + "『雙日煜林，震天極陽』" + NOR + "的真意﹐對$n四肢砍落!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + HIC + "『三日破星，破天極陽』" + NOR + "的真意﹐往$n胸前疾刺!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + HIM + "『四陽轉命，覆天元陽』" + NOR + "的真意﹐鶩然命行四轉砍向$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + HIY + "『乾坤五陽，震天元陽』" + NOR + "的真意﹐乾坤刀影包圍住$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + NOR + "" + WHT + "『陽六合明，破天元陽』" + NOR + "的真意﹐六道刀勁疾射向$n!\n"),me,victim);
     break;
     case 7:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + NOR + "" + BLU + "『七炩拱日，覆天真陽』" + NOR + "的真意﹐橫刀狂舞運化七燼攻向$n!\n"),me,victim);
     break;
     case 8:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + NOR + "" + CYN + "『陽格八鳴，震天真陽』" + NOR + "的真意﹐刀影朝八方點落包圍住$n!\n"),me,victim);
     break;
     case 9:
message_vision(sprintf("\n$N會意了" + HIW + "『天皇天式』中" + NOR + "" + MAG + "『九九玄陽，破天真陽』" + NOR + "的真意﹐刀氣疾走九宮集中射向$n!\n"),me,victim);
     break;
     }
if(me->query_skill("sunforce")+me->query_skill("surprise-ten") > random(180))
     {
message_vision(sprintf(HIR + "$N確實命中$n要害，$n頓時血流滿地。\n" + NOR),me,victim);
          victim->receive_wound("kee",vic_kee);
          victim->apply_condition("burn",random(45)+((int)me->query_skill("sunforce", 1)/10));//灼傷
          COMBAT_D->report_status(victim);
          me->add("force",-1000);
      }
       else
      {
message_vision(sprintf("結果$n迅速地避開這招。\n"),me,victim);
      }
   }
  }
}
void sp2(object me, object victim, object weapon, int damage)
{
        int ten, force;
        ten = me->query_skill("surprise-ten");
        force = me->query_skill("sunforce");
        if( random( force ) > random( ten ) )
        {
          message_vision(sprintf("" + HIC + "$N輕擺\衣袖﹐真氣混元歸一﹐婆娑瀟洒的身法、冰冷的拳勁與$n" + HIC + "交錯而過!!!\n" + NOR),me,victim);
          victim->receive_damage("kee",ten*9/2);
          victim->apply_condition("cold",random(45)+((int)me->query_skill("sunforce", 1)/10));//凍傷
          COMBAT_D->report_status(victim);
        }
}

void sp3(object me, object victim, object weapon, int damage)
{
        int force;
        force = me->query_skill("sunforce");
        if( me->query("force_factor") >= 10 && victim->query_condition("blockade"))
        {
          message_vision(sprintf("" + HIC + "$n抵擋不敵，被$N連勁劈中，身形巨震。$n內力突然破體宣洩而出，苦不堪言!!\n" + NOR),me,victim);
          victim->receive_damage("kee",force*6/5);
          victim->apply_condition("hart",random(45)+((int)me->query_skill("sunforce",1)/10));//內傷
          victim->start_busy(random(3));
          COMBAT_D->report_status(victim);
        }
}


mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("surprise-ten",1));

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 30 )
           return action [random(6)];
        else if ( level < 60 )
           return action [random(7)];
        else if ( level < 80 )
           return action [random(8)];
        else if ( level < 90 )
           return action [random(9)];
        else if ( level < 95 )
           return action [random(9)+1];
        else if ( level < 100 && me->query_temp("super",1))
           return action [random(9)+2];
        else if ( level >= 100 && me->query("marks/six_sp") ==3)
           return action [random(9)+3];
        else
           return action [random(9)];
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("練驚天十式是要空手吧....\n");
        if(me->query_skill("force")*3<=me->query_skill("surprise-ten",1))
          return notify_fail("你的基本內力技能不足, 無法練驚天十式。\n");
        if(me->query_skill("literate")*3<=me->query_skill("surprise-ten",1))
          return notify_fail("你的知識不足﹐無法體會驚天十式真切的要理﹐全身經脈真氣運行之道的精妙變化。\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("surprise-ten",1) >= 70)
         {
            return (usage=="unarmed")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("練驚天十式是要空手吧....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string perform_action_file(string action)
{
        return "/daemon/class/scholar/"+action;
}

