//修正錯字 by blazakira 2010/10/27
//增加receive_damage的攻擊者參數 by blazakira 2011/4/16

#include <combat.h>
#include <ansi.h>
inherit SKILL;
void hurt(object me, object victim, object weapon, int damage);
void block(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void sp1(object me, object victim, object weapon, int damage);
void sp2(object me, object victim, object weapon, int damage);
void sp3(object me, object victim, object weapon, int damage);
void sp_attack(object me, object victim, object weapon, int damage);
void sp_attack1(object me, object victim, object weapon, int damage);
mapping sp_action(object me,object weapon);
string *sword_name=({
    "少商劍法",
    "商陽劍法",
    "中衝劍法",
    "關衝劍法",
    "少衝劍法",
    "少澤劍法",
});

string *attack =({
//少商劍法 0~4
"$N拇指一拈﹐體內真氣流轉﹐使出" + HIW + "『少商劍』" + NOR + "中的" + HIY + "『穿雲裂石』" + NOR + "﹐其雄勁的劍路﹐霸道的向$n激射而去﹐頗有石破天驚﹐風雨大至之勢",
"$N勁透指尖﹐使出一招" + HIG + "『嶽峙淵渟』" + NOR + "﹐一道雄渾劍氣直刺$n﹐其嚴謹中正之姿﹐正符合" + HIW + "『少商劍』" + NOR + "大開大闔﹐氣派雄偉的劍意",
"$N拇指虛劃，使出" + HIR + "『" + HIY + "雲開見月" + HIR + "』" + NOR + ", 身形一轉,指尖逕向$n急點。",
"$N身形騰空而起, 拇指指尖微顫,朝$n點來, 正是一招" + HIG + "『" + HIC + "蜻蜓點水" + HIG + "』" + NOR + "。",
"$N拇指劍氣忽然光芒四射，身形急轉，使出一招" + HIR + "『" + HIY + "流星追月" + HIR + "』" + NOR + "，往$n攻去。",
//商陽劍法 5~9
"$N雙指齊出﹐兩股無形劍氣互相激盪﹐直奔$n而去﹐正是" + HIW + "『商陽劍』" + NOR + "中的絕招" + HIR + "『日月同耀』" + NOR,
"$N身形斗轉﹐一招" + HIC + "『霧捲雲湧』" + NOR + "幻化出無數身影﹐$n頓時籠罩在" + HIW + "『商陽劍』" + NOR + "無形劍氣之下",
"$N氣若凝淵, 化巧為拙,指尖往前平指, 使出了" + HIM + "『盤龍出谷』" + NOR + "。",
"$N劍走靈巧, 身法忽變,一招『虛空夜月』使將出來, 四周皆是身影。",
"$N使出『懷中抱月』, 手中劍尖微顫,旋即幻化出數朵劍花, 將$n籠罩在劍雨之下。",
//中衝劍法 10~14
"$N坦然地彈出中指﹐使出" + HIC + "『中衝劍』" + NOR + "中的" + CYN + "『千古人龍』" + NOR + "﹐其劍勢大開大闔﹐有如天外飛龍般﹐劍氣凌厲地朝向$n而去",
"$N伸出中指﹐一招" + HIW + "『中衝劍』" + HIB + "『雷震九重天』" + NOR + "射向$n﹐其聲勢如落雷驚天﹐叫人不敢逼視",
"$N左手捏個劍訣, 平推而出,訣指上仰, 右手中指朝天不動,正是一招『先人指路』。",
"$N面露微笑, 仰視蒼天,使出『捻花微笑』, 但見劍光閃閃，朝$n狂攻而去。",
"$N撮指成刀，忽地一招"+HIY+"「龍嘯九天」"+NOR+", 中指由下而上的砍向$n，因砍削空氣所形成得螺漩氣流如狂風般攻向$n。",
//關衝劍法 15~19
"$N緩緩的伸出無名指﹐「絲絲」聲起﹐正是" + HIW + "『關衝劍』" + NOR + "中的" + HIY + "『壯志凌雲』" + NOR + "﹐其拙滯古樸的劍勢籠罩住$n全身﹐直直的往$n撞去  ",
"$N潛運內力﹐以靜制動﹐一招" + HIG + "『時雨春風』" + NOR + "指向$n正面三十六大穴﹐其勢古樸﹐正是" + HIW + "『關衝劍』" + NOR + "裡的高招",
"$N忽然向前大跨一步，一股龐大的殺氣從$N身上湧出，$N大喝一聲"+HIR+"「殺龍求道」"+NOR+"，霍地旋身而起，氣隨身轉，旋風般朝$n猛攻。",
"$N將劍氣延申插入地面，身形急轉，大喝一聲"+HIY+"「潛龍升天」"+NOR+"，無名指劍氣帶起了一陣上升氣流，彷彿要將四週的一切全部捲到空中似的",
"$N大喝一聲使出" + HIG + "「峰迴路轉」" + NOR + "﹐無名指劍氣如一條銀蛇般刺向$n",
//少衝劍法 20~24
"$N小指靈巧的轉動﹐一招" + HIW + "『少衝劍』" + HIR + "『雪泥鴻爪』" + NOR + "刁鑽的朝$n飛去﹐其勢詭奇﹐叫人捉模不定",
"$N一招" + HIW + "『少衝劍』" + NOR + "刺向$n胸口﹐尚有許\尺﹐一斜身﹐小指迴轉﹐向$n削落﹐正是六脈神劍裡的妙招" + HIM + "『分花拂柳』" + NOR,
"$N身形有如陀螺般旋轉起來，一招" + HIW + "『少衝劍』" + HIY + "『洪流無限』" + NOR + "，劍氣有如箭搬不斷的朝$n攻去。",
"$N腳踩奇步，忽然繞到了$n的背後，一招" + HIW + "『少衝劍』" + HIG + "『柳暗花明』" + NOR + "往$n背心大穴急攻而去。",
"$N眼射精光﹐身形一轉急運小指劍氣，一招" + HIW + "『少衝劍』" + HBRED+HIY + "『空谷秋虹』" + NOR + "畫出一道光弧斬向$n",
//少澤劍法 25~29
"$N輕巧的轉動小指﹐使出一招" + HIC + "『飛雁迴翔』" + NOR + "﹐只見" + HIY + "『少澤劍』" + NOR + "忽來忽去﹐有如靈蛇般的斜射$n",
"$N展開架式﹐身法輕靈﹐無形劍氣左一拐﹐右一彎﹐越轉越急﹐鶩然間一劍刺向$n﹐正是" + HIY + "『少澤劍』" + NOR + "中的奇招" + HIW + "『非假非空』" + NOR,
"$N臉色忽白忽紅，只見$N小指劍氣越來越亮，一招" + HIY + "『少澤劍』" + HIY + "『氣遊天地』" + NOR + "，刺向$n。",
"$N小指虛劃十字，將劍氣凝聚胸前，一招" + HIY + "『少澤劍』" + BLINK+HIR + "『十方俱滅』" + NOR + "，劍氣有如排山倒海朝$n攻去。",
"$N騰身而起，小指劍氣聚而不散，身子有如箭一般的朝$n直射而去，正是" + HIY + "『少澤劍』" + NOR + "之" + BLINK+HIC + "『金光洩地』" + NOR,
});




mapping *action = ({

//1
([ "action":
"$N拇指一拈﹐體內真氣流轉﹐使出" + HIW + "『少商劍』" + NOR + "中的" + HIY + "『穿雲裂石』" + NOR + "﹐其雄勁的劍路﹐霸道的向$n$l激射而去﹐頗有石破天驚﹐風雨大至之勢",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  100,
        "damage_type":  "刺傷",
        "weapon": "拇指劍氣",
]),

//2
([ "action":
"$N勁透指尖﹐使出一招" + HIG + "『嶽峙淵渟』" + NOR + "﹐一道雄渾劍氣直刺$n$l﹐其嚴謹中正之姿﹐正符合" + HIW + "『少商劍』" + NOR + "大開大闔﹐氣派雄偉的劍意",
        "dodge": -30,
        "parry": -20,
        "damage": 100,
        "force":  100,
        "damage_type":  "刺傷",
        "weapon": "拇指劍氣",
]),

//3
([ "action":
"$N雙指齊出﹐兩股無形劍氣互相激盪﹐直奔$n$l而去﹐正是" + HIW + "『商陽劍』" + NOR + "中的絕招" + HIR + "『日月同耀』" + NOR,
        "dodge": -40,
        "parry": -15,
        "damage": 150,
        "force": 150,
        "damage_type": "刺傷",
        "weapon": "食指劍氣",
]),

//4
([ "action":
"$N身形斗轉﹐一招" + HIC + "『霧捲雲湧』" + NOR + "幻化出無數身影﹐$n頓時籠罩在" + HIW + "『商陽劍』" + NOR + "無形劍氣之下",
        "dodge": -40,
        "parry": -15,
        "damage": 150,
        "force": 150,
        "damage_type": "刺傷",
        "weapon": "食指劍氣",
]),

//5
([ "action":
"$N坦然地彈出中指﹐使出" + HIW + "『中衝劍』" + NOR + "中的" + CYN + "『千古人龍』" + NOR + "﹐其劍勢大開大闔﹐有如天外飛龍般﹐劍氣凌厲地朝向$n$l而去",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 200,
        "damage_type": "刺傷",
        "weapon": "中指劍氣",
        "post_action": (: block :),
]),

//6
([ "action":
"$N伸出中指﹐一招" + HIW + "『中衝劍』" + BLU + "『雷震九重天』" + NOR + "射向$n$l﹐其聲勢如落雷驚天﹐叫人不敢逼視",
        "dodge": -35,
        "parry": -20,
        "damage": 200,
        "force": 200,
        "damage_type": "刺傷",
        "weapon": "中指劍氣",
        "post_action": (: block :),
]),

//7
([ "action":
"$N緩緩的伸出無名指﹐「絲絲」聲起﹐正是" + HIW + "『關衝劍』" + NOR + "中的" + HIY + "『壯志凌雲』" + NOR + "﹐其拙滯古樸的劍勢籠罩住$n全身﹐直直的撞向其$l  ",
        "dodge": 25,
        "parry": 0,
        "damage": 250,
        "force": 250,
        "damage_type": "刺傷",
        "weapon": "無名指劍氣",
]),

//8
([ "action":
"$N潛運內力﹐以靜制動﹐一招" + HIG + "『時雨春風』" + NOR + "指向$n正面三十六大穴﹐其勢古樸﹐正是" + HIW + "『關衝劍』" + NOR + "裡的高招",
        "dodge": 25,
        "parry": 0,
        "damage": 250,
          "force": 250,
        "damage_type": "刺傷",
        "weapon": "無名指劍氣",
]),

//9
([ "action":
"$N小指靈巧的轉動﹐一招" + HIW + "『少衝劍』" + HIR + "『雪泥鴻爪』" + NOR + "刁鑽的朝$n$l飛去﹐其勢詭奇﹐叫人捉模不定",
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "刺傷",
        "weapon": "小指劍氣",
        "post_action": (: hurt :),
]),

//10
([ "action":
"$N一招" + HIW + "『少衝劍』" + NOR + "刺向$n胸口﹐尚有許\尺﹐一斜身﹐小指迴轉﹐向$n$l削落﹐正是六脈神劍裡的妙招" + HIM + "『分花拂柳』" + NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "割傷",
        "weapon": "小指劍氣",
]),

//11
([ "action":
"$N輕巧的轉動小指﹐使出一招" + HIC + "『飛雁迴翔』" + NOR + "﹐只見" + HIW + "『少澤劍』" + NOR + "忽來忽去﹐有如靈蛇般的斜射$n$l",
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "刺傷",
        "weapon": "小指劍氣",
]),

//12
([ "action":
"$N展開架式﹐身法輕靈﹐無形劍氣左一拐﹐右一彎﹐越轉越急﹐鶩然間一劍刺向$n$l﹐正是" + HIW + "『少澤劍』" + NOR + "中的奇招" + HIW + "『非假非空』" + NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 250,
        "force": 250,
        "damage_type": "刺傷",
        "weapon": "小指劍氣",
        "post_action": (: hurt :),
]),

//13
([ "action":
HIW + "$N大喝一聲﹐鼓動全身真氣﹐內勁流轉﹐雙手六劍齊發﹐十指分彈﹐霎時劍氣縱橫﹐似有無數迅雷疾風互衝激盪向$n而去" + NOR,
        "dodge": -50,
        "parry": -20,
        "damage": 300,
        "force": 300,
        "damage_type": "刺傷",
        "weapon": "無形劍氣",
        "post_action": (: conti :),
]),

//14奧義(一)
([ "action":
HIY + "\n$N眼中精光大盛﹐大喝:\n\n" + HIW + "             『\n" + HIR + "                奪命" + HIW + "～" + HIG + "連環" + HIW + "～" + HIM + "六絕劍" + HIW + "!!\n"
"                                     』\n"
"$N突然急運『一陽心法』﹐氣勁滿盈﹐一個箭步﹐向$n縱身飛去\n" + NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "創傷",
        "post_action": (: sp1 :),
]),

//15奧義(二)
([ "action":
HIY + "\n$N緩緩念道:\n\n" + NOR + GRN + "                   『 兩腳踏翻塵世路﹐一肩擔盡古今愁 』\n\n" + HIW + "配合『凌波微步』的精妙步法﹐幻化成無數人影包圍$n﹐雙手疾射﹐六劍齊發﹐霎時
間$n陷入無形劍氣的狂亂劍網之中﹐劍氣激盪﹐竟是要將$n全身撕裂﹐此招正是
大理段氏的禁用殺招\n\n"
"                         ～ " + HIY + " 無" + HIM + " 常" + HIW + " ．" + RED + " 恨" + HIC + " 蒼" + BLU + " 天 " + HIW + " ～\n\n" + NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
          "force": 300,
        "damage_type": "刺傷",
        "post_action": (: sp2 :),
]),


//16奧義(三)
([ "action":
HIY + "\n$N回身收步長吟道:\n\n" + NOR + YEL + "                   『 明月浮雲相半掩﹐七星不落耀長空 』\n\n" + HIW + "忽然間高高躍起﹐身形掩空﹐左掌撫胸﹐右手連發七道無形劍氣﹐疾向$n周身要穴而
去﹐昏暗之中﹐只見七道劍芒金光耀眼﹐乃是大理段氏六脈神劍中的絕學\n\n"
"                           ～" + HIM + " 七" + HIY + " 星" + HIC + " 落" + HIG + " 長" + HIR + " 空" + HIW + " ～\n\n" + NOR,
        "dodge": 80,
        "parry": 50,
        "damage": 300,
        "force": 300,
        "damage_type": "刺傷",
        "post_action": (: sp3 :),
]),
//17少商劍法
([ "action":
"$N" + HIR + "使出六脈神劍中的『少商劍法 』，拇指劍氣有如實質，往" + NOR + "$n" + HIR + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                330,
                "force"      :                330,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//18商陽劍法
([ "action":
"$N" + HIY + "使出六脈神劍中的『商陽劍法 』，食指劍氣有如實質，往" + NOR + "$n" + HIY + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                340,
                "force"      :                340,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//19中衝劍法
([ "action":
"$N" + HIC + "使出六脈神劍中的『中衝劍法 』，中指劍氣有如實質，往" + NOR + "$n" + HIC + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                350,
                "force"      :                350,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//20關衝劍法
([ "action":
"$N" + HIG + "使出六脈神劍中的『關衝劍法 』，無名指劍氣有如實質，往" + NOR + "$n" + HIG + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                360,
                "force"      :                360,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//21少衝劍法
([ "action":
"$N" + HIB + "使出六脈神劍中的『少衝劍法 』，小指劍氣有如實質，往" + NOR + "$n" + HIB + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                370,
                "force"      :                370,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//22少澤劍法
([ "action":
"$N" + HIM + "使出六脈神劍中的『少澤劍法 』，小指劍氣有如實質，往" + NOR + "$n" + HIM + "攻去。" + NOR,
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                380,
                "force"      :                380,
                "post_action":                (: sp_attack :),
                "damage_type":               "刺傷"
]),
//23六劍合一
([ "action":
"$N領悟到六脈神劍" + BLINK+HBRED+HIY + "「圓滿如意，運轉不息」" + NOR + "的真意，劍氣齊發，往$n攻去。",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                400,
                "force"      :                400,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "刺傷"
]),

});

int AlwaysSuccess(object me, object victim)
{
  if(me->query("marks/handwriting") && //解過臨書點穴
     me->query("marks/linpo-steps") && //解過凌波微步
     me->query_skill_mapped("dodge") == "linpo-steps" && //使用凌波微步
     me->query("functions/handwriting/level") >= 100 && //fun 100以上
     victim->is_busy()) //敵人無法動彈
  {
    return 1;
  }
  return 0;
}

void hurt(object me, object victim, object weapon, int damage)
{
        int force;
        if( (random(100)>50 || AlwaysSuccess (me,victim)) && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="段家" )
        {
          force = me->query_skill("sunforce",1);
          if(force > 250) force=250;
          victim->receive_damage("kee", 50+force,me);
          message_vision(sprintf(HIM + "$N六脈神劍詭異的氣勁鑽入$n體內﹐$n臉上突然一陣青白﹐看來已受了不小的內傷。\n" + NOR),me,victim);
          COMBAT_D->report_status(victim);
          me->add("force",-force);
        }
        else
        {
          message_vision(sprintf(HIW + "$n狼狽地閃過了$N的詭異氣勁, 但已大大出糗。\n" + NOR),me,victim);
        }
}
void block(object me, object victim, object weapon, int damage)
{
        if( (random(100)>50 || AlwaysSuccess (me,victim)) && !me->query_temp("conti",1) &&
            me->query("family/family_name")=="段家" )
        {
          victim->apply_condition("blockade",3);
          message_vision(sprintf(HIY + "$N六脈神劍暗藏一陽指手法﹐反手點中$n的膻中大穴。\n" + NOR),me,victim);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
        }
        else
        {
          message_vision(sprintf(HIW + "$N試圖以一陽指封鎖$n, 但是被$n躲了開來。\n" + NOR),me,victim);
        }
}
void conti(object me, object victim, object weapon, int damage)
{
         int i,time = 3;
        if( me->query("force_factor") >= 10 &&
            me->query("family/family_name")=="段家" && (70>random(100) || AlwaysSuccess (me,victim)) )
        {
          if( me->query_temp("conti") == 0 )
          {
            me->delete_temp("super");
            me->set_temp("conti",1);
      message_vision(sprintf("\n$N忽然頓悟六脈神劍氣遊百穴、連綿不絕的要訣, 劍氣自然而然的破體而出, 欲罷不能!!\n"),me);
              for(i=1;i<=time;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
            me->delete_temp("conti");
          }
        }
}

void sp1(object me, object victim, object weapon, int damage)
{
int i;
if(me->query("env/六絕劍","YES")&&!me->query_temp("conti",1))
{
  for(i=1;i<=6;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf("$N領悟了" + HIW + "『少商劍』" + HIY + "『氣湧如山﹐席捲天下』" + NOR + "的真意﹐向$n當頭斬下!\n"),me,victim);
     break;
     case 2:
message_vision(sprintf("\n$N領悟了" + HIW + "『商陽劍』" + HIG + "『身形靈動﹐勢若流雲』" + NOR + "的真意﹐對$n四肢砍落!\n"),me,victim);
     break;
     case 3:
message_vision(sprintf("\n$N領悟了" + HIW + "『中衝劍』" + HIC + "『劍氣沖天﹐盈不可久』" + NOR + "的真意﹐往$n胸前疾刺!\n"),me,victim);
     break;
     case 4:
message_vision(sprintf("\n$N領悟了" + HIW + "『關衝劍』" + HIM + "『氣凝丹田﹐以靜制動』" + NOR + "的真意﹐鶩然間刺向$n!\n"),me,victim);
     break;
     case 5:
message_vision(sprintf("\n$N領悟了" + HIW + "『少衝劍』" + CYN + "『應左則右﹐虛幻不定』" + NOR + "的真意﹐劍影包圍住$n!\n"),me,victim);
     break;
     case 6:
message_vision(sprintf("\n$N領悟了" + HIW + "『少澤劍』" + BLU + "『雲譎波詭﹐亦幻亦真』" + NOR + "的真意﹐劍氣疾射向$n!\n"),me,victim);
     break;
     }
message_vision(sprintf(HIR + "$N確實命中$n要害，$n頓時血流滿地。\n" + NOR),me,victim);
          victim->receive_damage("kee",150,me);
          COMBAT_D->report_status(victim);
          me->add("force",-20);
   }
message_vision(sprintf(HIW + "\n你使力過度,一時之間無力再戰!\n" + NOR),me,victim);
if(!me->query_temp("weapon")){
me->start_busy(1);
}
else
{
weapon=me->query_temp("weapon");
if(weapon->query("six_no_delay") && me->query("family/family_name")=="段家")
{
message_vision("可是$N手中的$n卻發出了淡淡藍光，讓$N的力氣回復，隨時可以戰鬥!!\n",me,weapon);
me->add("force",-20);
}
else
{
me->start_busy(1);
}
}
 }
}
void sp2(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int six, force;
        six = me->query_skill("six-fingers",1);
        force = me->query_skill("sunforce",1);
        if(force>250) force=250;
          message_vision(sprintf(HIG + "$N縱聲長嘯﹐雙手混元歸一中宮直入﹐無數道劍氣在$n身上對穿而過!!\n" + NOR),me,victim);
          victim->receive_damage("kee",six+force,me);
          victim->apply_condition("bleeding",5);
          COMBAT_D->report_status(victim);
}
}
void sp3(object me, object victim, object weapon, int damage)
{
if(!me->query_temp("conti",1)) {
        int force;
        force = me->query_skill("sunforce",1);
        if(force > 350) force=350;
          message_vision(sprintf(HIC + "$n先前內傷受到$N無形劍氣牽引﹐$n的傷勢更加重了!!\n" + NOR),me,victim);
          victim->receive_damage("kee",force,me);
          victim->start_busy(1);
          COMBAT_D->report_status(victim);
}
}
void sp_attack(object me, object victim, object weapon, int damage)
{
    int i,sklv,str,range;
    string sp_name;
    if(!me || !victim) return ;
    if(!damage && !AlwaysSuccess (me, victim)) return ;
    if(me->query("force") < 200) return ;
    sklv=me->query_skill("six-fingers",1);
    if(sklv > 120 && userp(me) && !wizardp(me)) sklv=120;
    str=victim->query_str();
    if(str > 35 ) str=35;
    sklv*=(5+random(3));
    str*=(6+random(5));
    if(sklv < str) sklv=str+random(10);
    range=me->query_temp("skills/six-fingers");
    if(!range) return;
    range*=5;
    switch(random(5))
    {
      case 0..3:
        i=range+random(4);
        message_vision(attack[i],me,victim);
        if((random(me->query("combat_exp")) > random(victim->query("combat_exp"))/6) ||
           AlwaysSuccess (me, victim)) {
          message_vision("\n$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , victim);
          victim->set_temp("no_armor_effect",1);
          victim->receive_damage("kee",sklv-str,me);
          COMBAT_D->report_status(victim);
          if(range==10)
            block(me,victim,weapon,damage);
          if(range==20)
            hurt(me,victim,weapon,damage);
        }
        else{
          message_vision("\n$N身形一閃, 驚險地閃過了這一招。\n" , victim);
        }
        break;
      case 4:
       for(i=range;i<(range+5);i++){
        if(i >=sizeof(attack)) continue;
        message_vision(attack[i],me,victim);
        if((random(me->query("combat_exp")) > random(victim->query("combat_exp"))/6) ||
           AlwaysSuccess (me, victim)) {
          message_vision("\n$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , victim);
          me->add("force",-30);
          victim->set_temp("no_armor_effect",1);
          victim->receive_damage("kee",(sklv-str)*2,me);
          COMBAT_D->report_status(victim);
          if(range==20)
            hurt(me,victim,weapon,damage);
        }
        else{
          message_vision("\n$N身形一閃, 驚險地閃過了這一招。\n" , victim);
        }
       }
       if( random(me->query_cps()) < 4 ) {
          me->add("force",-100);
          range/=5;
          sp_name=sword_name[range];
          message_vision("\n$N使完" + HIY + "『"+sp_name+"』" + NOR + "後，由於定力不足，體內真氣一時無以為繼\n",me);
          me->start_busy(1);
       }
       break;
    }
}
void sp_attack1(object me, object victim, object weapon, int damage)
{
    int i,sklv,str,limit,value;
    if(!me || !victim) return ;
    if(!damage && !AlwaysSuccess (me, victim)) return ;
    if(me->query("force") < 1000)
      return notify_fail("你的真氣不足，無法使出六脈神劍連續技!!\n");
    sklv=me->query_skill("six-fingers",1);
    if(sklv > 120 && userp(me) && !wizardp(me)) sklv=120;
    str=victim->query_str();
    if (str > 35) {
      str = 35;
    }
    sklv*=(5+random(3));
    str*=(6+random(5));
    if(sklv < str) sklv=str+random(10);
    switch(me->query("combat_exp")){
      case 2000000..5000000:
        limit=3;
        break;
      case 5000001..8000000:
        limit=2;
        break;
      case 8000001..32000000:
        limit=1;
        break;
      default:
        if (me->query("combat_exp") > 32000000) {
          limit = 0;
        } else {
          tell_object(me,"你感到頭腦昏昏沉沉，無法使出連續技!!\n");
          return ;
        }
        break ;
    }
    if(wizardp(me) && me->query("env/超級連擊")) limit=0;
    value = (sklv-str)*2;
    if (value < 100) {
      value = 100;
    }
    for(i=0;i<sizeof(attack);i++){
     if(i % 5 >= (5-limit)) continue;
     message_vision(attack[i],me,victim);
     if((random(me->query("combat_exp")) > random(victim->query("combat_exp"))/6) ||
       AlwaysSuccess (me, victim)) {
       message_vision("\n$N閃躲不及，身上頓時多出了一道血淋淋的劍痕。\n" , victim);
       me->add("force",-30);
       victim->receive_damage("kee",value,me);
       COMBAT_D->report_status(victim);
     }
     else{
       message_vision("\n$N身形一閃, 驚險地閃過了這一招。\n" , victim);
     }
    }
    if( random(me->query_cps()) < 4 ) {
       me->add("force",-100);
       message_vision("\n$N使完" + HIY + "『六脈奧義連續技』" + NOR + "後，由於定力不足，體內真氣一時無以為繼\n",me);
       me->start_busy(1);
    }
}
mapping sp_action(object me,object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));
        int plus,value;

        if(level/2 > random(100) && me->query_temp("super")){
          me->delete_temp("super");
          me->set_temp("skills/six-fingers",6);
          return action[22];
        }
        value=random(2100);
        if(value > 2000) return action[22];
        else{
          plus=(int)(value/200);
          if(plus==10) plus--;
          if(plus-4>=0)
            me->set_temp("skills/six-fingers",plus-4);
          return action[12+plus];
        }
}
mapping query_action(object me, object weapon)
{
        int level=(int)(me->query_skill("six-fingers",1));

        if(me->query("marks/six-fingers")==3 && level >=100 && !me->query_temp("conti"))
          return sp_action(me,weapon);

        if ( level < 10 )
           return action [random(3)];
        else if ( level < 20 )
           return action [random(5)];
        else if ( level < 30 )
           return action [random(7)];
        else if ( level < 40 )
           return action [random(9)];
        else if ( level < 50 )
           return action [random(11)];
        else if ( level < 60 )
           return action [random(13)];
        else if ( level < 70 )
           return action [random(9)+4];
        else if ( level >= 70 && me->query_temp("super",1))
           return action [12];
        else if ( level >= 100 && me->query("marks/six_sp")==3 &&
                  me->query("family/family_name") == "段家")
           return action [random(12)+4];
        else
           return action [random(8)+5];
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("練六脈神劍還是要空手吧....\n");
        if(me->query_skill("force")*3<=me->query_skill("six-fingers",1))
          return notify_fail("你的基本內力技能不足, 無法練六脈神劍。\n");
        if(me->query_skill("literate")*3<=me->query_skill("six-fingers",1))
          return notify_fail("你的知識不足﹐無法體會六脈神劍裡﹐全身經脈運行之道的精要變化。\n");
        return 1;
}

int valid_enable(string usage)
{
      if(this_player()->query_skill("six-fingers",1) >= 45)
         {
            return (usage=="unarmed"||usage=="stabber")||(usage=="parry");
         }
          return (usage=="unarmed");
}

int practice_skill(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("練六脈神劍還是要空手吧....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("體力不夠囉,休息一下再繼續練吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        me->receive_damage("gin", 5,me);
        me->receive_damage("kee", 30,me);
        me->add("force", -1);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("scholar")+"/six-fingers/"+action;
}
