//皇拳 by bss
//皇城mob專用，不開放
//借用roger && taifar所寫sun_fire_sword的連擊程式
#include <ansi.h>
#include <combat.h>
inherit SKILL;
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);

string *taiganfist = ({
"$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIC"陰"NOR"招的起手式"HIC"「蒼松迎客」"NOR"，右掌平推而出，一道寒風由$N掌中拍出，令人不禁打起冷顫。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中"HIR"陽"NOR"招的起手式"HIR"「開門輯盜」"NOR"，左掌由上而下猛劈而出，一股熱風隨著$N的掌勢而出，使人有種不舒服的悶熱感。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「梅雪爭春」"NOR"，右掌如雪花翻飛擊向$n。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「梅雪逢夏」"NOR"，左掌如連珠般向$n拍出了一十二掌。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「老枝橫斜」"NOR"，左掌平舉，右掌由左脅下斜穿而出，擊向$n的$l。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「長者折枝」"NOR"，左掌高舉，迅速地下拍擊向$n的$l。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「明駝西來」"NOR"，右掌並指成劍，迅雷般刺向$n的$l。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「千鈞壓駝」"NOR"，左掌撮指成刀，疾電般劈向$n的$l。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIC"陰"NOR"招"HIC"「風沙莽莽」"NOR"，右掌掌勢似有狂風黃沙之重壓，教$n透不過氣來。\n",
"$N使出"HIC"陰"HIR"陽"NOR"掌法中的"HIR"陽"NOR"招"HIR"「大海沉沙」"NOR"，左掌掌勢如有怒海洪濤之洶湧，教$n心驚膽顫。\n",
});

string *fon_un = ({
HIW"\n風雲連續掌第一式"HIB"『行雲流水』"HIW"，招式有如流水般朝$n攻去，使人目不暇己\n"NOR,
HIW"\n風雲連續掌第二式"HIB"『披星戴月』"HIW"，右手中指忽然朝$n直刺過去，刺中了$n身上幾大要穴\n"NOR,
HIW"\n風雲連續掌第三式"HIB"『翻雲覆雨』"HIW"，$N雙掌如風車般在$N身旁轉了起來，$n被招式所產生的\n\n螺漩氣流所侵，受了重傷\n"NOR,
HIW"\n風雲連續掌第四式"HIB"『排山倒海』"HIW"，$N將雙掌插入土地，跟著用力拔起，隨掌勢而飛起的土石\n\n擊中了$n\n"NOR,
HIW"\n風雲連續掌第五式"HIB"『重雲深鎖』"HIW"，$N雙掌$n身上畫了十幾個小圓圈，$n\n\n忽然身體一震，動彈不得\n\n"NOR,
HIW"\n風雲連續掌第六式"HIB"『風捲殘樓』"HIW"，$N拔身而起，身體圓轉，如一道龍捲風般朝$n攻去\n"NOR,
HIW"\n風雲連續掌第七式"HIB"『狂風暴雨』"HIW"，招式連綿不絕的朝$n攻去，使$n身受重創\n"NOR,
HIW"\n風雲連續掌第八式"HIB"『神風怒嚎』"HIW"，右掌撮指成刀在空間中快速的砍劈，使四週產生了巨大的破空聲\n"NOR,
HIW"\n風雲連續掌第九式"HIB"『撕天排雲』"HIW"，$N雙掌合並，將高度集中的勁氣聚在掌心，忽然向外一推，\n\n一道驚人氣勁朝$n攻去。\n"NOR,
HIW"\n風雲連續掌第十式"HIB"『雲海波濤』"HIW"，勁氣如巨浪狂湧而至，$n連閃避的機會也沒有\n"NOR,
HIW"\n風雲連續掌第十一式"HIB"『殃雲天絳』"HIW"，$N躍至空中，雙掌朝$n用力下拍，掌氣充斥著這整個空間\n"NOR,
});


mapping *action = ({
(["action":
HIY"$N"HIY"身形立定，使出皇拳第一式"HIC"「君臣之禮」"HIY"，$N"HIY"弓身，曲膝，身子如一隻箭般朝$n射去，
，正當$n擺\好姿勢想要閃躲$N"HIY"這致命一擊時，$N"HIY"的身體忽然違反常理的停在半空中，變成
頭上腳下，雙手往地上用力一撐，右腳向上猛踢，眼看就要擊中$n的下巴了"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踢傷",
        "post_action":          (: sp_attack:),
]),
(["action":
HIY"$N"HIY"暗運心法，使出皇拳第二式"HIC"「天下大道」"HIY"，雙手合十，將高度集中的勁氣聚在雙手掌
心，雙手向外一推，一股排山倒海的勁氣襲向$n，正當$n氣集雙臂準備硬接這股要人命的
勁氣時，$N"HIY"忽然在$n的右方出現，右腳往$n的小腹猛踹"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踹傷",
]),
(["action":
HIY"$N"HIY"緊握雙拳，使出皇拳第三式"HIC"「問鼎中原」"HIY"，雙拳猛力地往地面一擊，使地面不住的震
動，$n立足不穩，竟被這由地面傳出的勁氣震到了空中，$N"HIY"全身勁力一提，有如砲彈一
般地擊向$n，$n因身在半空中無處著力，眼看就要被擊中了"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌傷",
        "post_action":          (: sp_attack:),
]),
(["action":
HIY"$N"HIY"化拳為掌，使出皇拳第四式"HIC"「千軍萬馬」"HIY"，一個巨大掌影鋪天蓋\地的向$n襲去，剎時
，$n有一種置身在於漩渦內的眩然感覺，$n身形立定，舉臂格檔，就在巨掌快要擊中
$n的剎那，$N"HIY"的巨靈一掌，竟突然急轉為細如毛針般的亂空掌影，一時$n的四面八方都
是疾湧狂飆的掌影"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌傷",
        "post_action":                (: sp_attack5 :),
]),
(["action":
HIY"$N"HIY"眼中精光暴放，使出皇拳第五式"HIC"「黃袍加身」"HIY"，猛烈的近乎異常的勁氣，朝$n襲去，
那樣的猛烈拳勢，彷彿真能裂石崩山，強厲的氣勁，似乎要將人活生生撕碎的湧往$n"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌傷",
        "post_action":  (:sp1:),
]),
(["action":
HIY"$N"HIY"使出皇拳第六式"HIC"「雄霸天下」"HIY"，雙拳如連珠般連續不斷的擊出，乍看之下全無章法，
但每拳都從$n想都想不到得地方擊出，充滿了天馬行空的想法，使$n愈抵擋愈心驚，逐
漸地喪失了信心"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "掌傷",
        "post_action":                (: sp_attack0 :),
]),
(["action":
HIY"$N"HIY"緩緩閉上雙眼，剎那間進入了萬里空晴的心法最高境界，使出皇拳第七式"HIC"「九五之尊」"HIY"
，$N"HIY"清楚的知道了$n的強弱，看準了時機，一拳擊出，$n哈哈大笑道：「爾等技止於此啦
」，正欲變招反擊，沒想到$N"HIY"只是虛招，真正的殺手卻在$N"HIY"的右腳，$n臉色大變，因為此
腳擊出的角度及時機均是$n想都沒想到的"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "踢傷",
]),
(["action":
HIY"$N"HIY"向前大跨一步，殺氣從$N"HIY"的身後湧出，使出了皇拳第八式"HIC"「震怒龍顏」"HIY"，只見$N"HIY"勁貫
右臂，大喝一聲：「龍拳暴發」，右拳猛力朝$n擊出，拳勁化為一隻神龍，如龍卷風般向
著$n卷去，四週空氣受到拳勁影響也激起了大大小小不同的旋風，使得$n難以動彈"NOR,
        "damage":       300,
        "dodge":        -100,
        "parry":        -100,
        "force":        100,
        "damage_type" : "擊傷",
        "post_action":  (:sp2:),
]),
});
int valid_learn(object me)
{
        return 1;
}
int valid_enable(string usage)
{
        return (usage=="unarmed");
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("kingfist", 1);
   message_vision("$N被招式所帶起的上升氣流，捲至空中並被撕裂開來\n",victim);
   victim->receive_damage("kee", (skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("kingfist",1)/5));
   COMBAT_D->report_status(victim);
   victim->start_busy(2);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("kingfist", 1);
   if(70 > random(100))
   {
   message_vision(HIY"
                  _-~~~~~~-_/|          ._---;/^ ^   `./|
           v     /^^ v  ^^  ~/|         (( );/^     > > `/|
   \\     (:)   /^ ^(:)  ^  >>`/|          ,/ ^^  >    > >`/|
    \\    (::) /   (::) ;> / >>`/|        ,/^^^   ,-.   > >>`/|
     \\   (::),~~~.(::)/`/   >>>`/|      ,/^^   ^;   `.   > >`/|
       \\  <_):::::(_>/ /`._--.  `/|     ;/^  ^  ;-_.  `.. >  >`/|
        \\ \\|:::|:::|/ /   ( ))  >`/|   ,/^ ^   ;( ))     ;  >> `/
         \\  \\_:|:_/  /    `.     >`/| ,/^^   ^ ;          ;>  > /;
          \\ \\@, .@/ /      `.  > > `-- ^  ^   ;           :  > /.'
           \\ \\=:=/ /       _`.    >  > >  >  ;           ,` >  /;
            \\\\=:=//       ((,`.> >    > > _/           ,' > > /'
            < o_o >           ~`-__ > ___-~          _,' > > /;
                                  ~~~     ~~_-~=--~~ >> /_;/
                                          _~   _~--____-~



   氣勁化成的巨龍，竟然纏繞住$N的身體，使$N完全無法動彈，任人宰割。\n"NOR,victim);
   victim->receive_damage("kee", (skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("kingfist",1)/5));
   COMBAT_D->report_status(victim);
   victim->start_busy(5);
   }
   else
   {
   message_vision("$N急運身法，才堪堪避過了這致命的一擊。\n",victim);
   }
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


  if( 21 > random(30) && me->query("force") > 360 && !me->query_temp("con_ti",1)) {

message_vision(HIM"
$N臉上紫氣浮現，全身勁氣擴張，身體騰空而起，大喝一聲:
「"HIB"陰"HIR"陽"HIG"連續掌!!!」"HIM"，以及快的速度拍出
令人至命的掌法!!!
\n"NOR,me,victim);

    for(j=0; j < 10; j++) {
       do_action = taiganfist[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision(HIR"\n$N閃躲不及，被重重得擊中。\n"NOR , enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N，展開身形， 驚險地閃過了這一招。\n" , enemy[i]);
                             }

        me->add("force",-100);
        message_vision("\n$N使完「"HIB"陰"HIR"陽"HIG"連續掌"NOR"!!!」後，由於定力不足，體內真氣一時無以為繼\n",me);
        me->start_busy(1);
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


  if( 21 > random(30) && me->query("force") > 510 && !me->query_temp("con_ti",1)) {
message_vision(BLINK+HIG"
\n$N忽然眼放精光，大喝一聲「風雲連續掌」，剎那間四週湧起一道黑雲，使$n完全失去$N的蹤影!!\n\n
\n$N以傳音之術對$n說到:「接招吧」，招式如狂風般朝$n襲至!!\n\n
"NOR,me,victim);
    for(j=0; j < 11; j++) {
       do_action = fon_un[j];
       actionn = "\n";
       actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
          if( random(me->query("combat_exp")) >
        random(enemy[i]->query("combat_exp"))/6 ) {
        message_vision(HIR"\n$N閃躲不及，慘叫一聲，被重重的拍到。\n"NOR , enemy[i]);
        enemy[i]->receive_damage("kee",50,me);
        me->add("force",-30);
        COMBAT_D->report_status(enemy[i]);
                                                  }
   else message_vision("\n$N人比招快，驚險地閃過了這一招。\n" , enemy[i]);
                             }

        me->add("force",-100);
        message_vision("\n$N使完「風雲連續掌」後，由於定力不足，體內真氣一時無以為繼\n",me);
        me->start_busy(1);
                                                  }

}
void sp_attack(object me,object victim, object weapon,int damage)
{
 int i,j;
 if(80 > random(100)&& !me->query_temp("conti")){
message_vision(HIY"\n$N殺的興起，眼中血光一現，有如神龍般使出連擊技。\n"NOR,me,weapon);
  me->set_temp("conti",1);
  victim->start_busy(2);
  switch(random(5)){
        case 1:
                j=4;
                break;
        case 2:
                j=5;
                break;
        case 3:
                j=6;
                break;
        case 4:
                j=7;
                break;
        case 5:
                j=8;
                break;
        default:
                j=6;
                break;
     }
   for(i=0;i<j;i++)

    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

    me->delete_temp("conti");
                     }
}
