// linbo-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg =
({
"$n展開『凌波微步』﹐左足跨出﹐既踏「中孚」﹐立轉「既濟」﹐「神光離合﹐乍陰乍陽」﹐斜斜的躲過$N。\n",
"只見$n施展『凌波微步』﹐甫上「泰」位﹐一個轉身﹐右腳踏上「蠱」位﹐「體迅飛鷲﹐飄忽若神」﹐反而繞到$N身後。\n",
"$n踏出『凌波微步』﹐足下自然而然自「井」位斜行﹐踏到了「訟」位﹐「涑輕軀以鶴立﹐若將飛而未翔」﹐輕輕鬆鬆地躲過$N的招式。\n",
"$n使出『凌波微步』﹐自「豫」位踏「觀」位﹐「翩若驚鴻﹐婉若遊龍」﹐閃身從$N身旁繞過。\n",
"$n展現『凌波微步』﹐跟著斜踏「蠱」位﹐「忽焉縱體﹐以遨以嘻」﹐身子輕輕飄了開去。\n",
"$n斜踏『凌波微步』﹐忽高忽低﹐有若「髣彿兮若輕雲之蔽月﹐飄飄兮若流風之回雪」般。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
        if(me->query_skill("literate",1)*2 <= me->query_skill("linpo-steps",1))
        {
          write("你的知識不足﹐無法體會凌波微步中易經六十四卦的精要變化。\n");
          return 0;
        }
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練凌波微步。\n");
        me->receive_wound("kee",5);
        return 1;
}
/*希望能設計成考慮以下
1.出口的個數
2.敵人的exp和自己的exp
3.是否真的有使用linpo-steps在dodge and move上
*/
int can_flee(object me,int exit_number)
{
    object *enemy;
    int i,enemy_num,enemy_exp,me_exp,ratio;

    if(!me) return 0;
    if(!me->query("marks/linpo-steps")) return 0;
    if(me->query("force") <100) return 0;
    if(me->query_skill_mapped("dodge") != "linpo-steps" ||
       me->query_skill_mapped("move") != "linpo-steps") return 0;
    enemy=me->query_enemy();
   if(!sizeof(enemy)) return 0;
/*
    if(sizeof(enemy) <1){
     message_vision(
"$N忽然領悟" + HIC + "『凌波微步』" + NOR + "的要旨所在，腳步作到" + HIY + "「動無常則，若危若安，進止難期，
若往若還」" + NOR + ",霎時一片人影紛飛，讓敵人頭昏眼花\n",me);
     message_vision(HIM + "$N" + HIM + "看準時機，使出凌波微步，逃離戰圈!!\n" + NOR,me);
     return 1;
    }
*/
    me_exp=me->query("combat_exp");
    enemy_exp=0;
    enemy_num=0;
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(enemy[i]->query("combat_exp") < (int)(me_exp*2/3)) continue;
      enemy_exp+=enemy[i]->query("combat_exp");
      enemy_num++;
    }
    if(!enemy_num){
     message_vision(
"$N忽然領悟" + HIC + "『凌波微步』" + NOR + "的要旨所在，腳步作到" + HIY + "「動無常則，若危若安，進止難期，
若往若還」" + NOR + ",霎時一片人影紛飛，讓敵人頭昏眼花\n",me);
     message_vision(HIM + "$N" + HIM + "看準時機，使出凌波微步，逃離戰圈!!\n" + NOR,me);
     return 1;
    }
    enemy_exp/=enemy_num;
    if(exit_number >=4) ratio=100;
    if(exit_number ==3) ratio=82;
    if(exit_number ==2) ratio=66;
    if(exit_number ==1) ratio=50;
    if(exit_number ==0) return 0;
    if(!me->is_busy() && ratio > random(110) && me->query("kee")<=(me->query("max_kee")/3)) {
      if(enemy_exp < me_exp * 2){
       message_vision(
"$N 心中默念，將" + HIC + "『凌波微步』" + NOR + "的六十四卦步法，自「明夷」起始，經「賁」
 、「既濟」、「家人」，走了一大圈而至「旡妄」，終於順利擺\脫敵人的糾纏。\n" + NOR,me);
        message_vision(HIM + "$N" + HIM + "看準時機，使出凌波微步，逃離戰圈!!\n" + NOR,me);
        me->add("force",-200);
        return 1;
      }
      else{
        if((100*me_exp/enemy_exp) > random(110)){
          me->add("force",-200);
       message_vision(
"$N 心中默念，將" + HIC + "『凌波微步』" + NOR + "的六十四卦步法，自「明夷」起始，經「賁」
 、「既濟」、「家人」，走了一大圈而至「旡妄」，終於順利擺\脫敵人的糾纏。\n" + NOR,me);
          message_vision(HIM + "$N" + HIM + "看準時機，使出凌波微步，逃離戰圈!!\n" + NOR,me);
          return 1;
        }
      }
    }
    return 0;
}
