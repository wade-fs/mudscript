// lum-steps.c
#include <ansi.h> 
inherit SKILL;
inherit SSERVER;          
string *dodge_msg = ({
"$n面露淡淡的微笑，柳腰一轉，一招" + HIM + "「月兒倒鉤」" + NOR + "，不慌不忙的輕輕閃過$N的殺著。\n",
"$n口中輕唸" + HIM + "「輕問清風聲，聞聲不見人」" + NOR + "，一雙金蓮猶如幻化千百雙，$N的眼前瞬間\n出現好幾個人的身影，不知道哪個才是真的。\n",
"只見$n裙角一擺\，$n的身影已轉到$N身後，並對著$N露出淺淺的一笑。\n",
"$n輕輕的原地旋轉，舞出了" + HIM + "「落花散月，流水耀星」" + NOR + "，身子忽快忽慢，忽前忽後，\n實在是美不勝收，只見$N呆呆站立，不曉得在想什麼。\n",
"$n袖子輕掩嘴角，左手輕捻，一招" + HIM + "「麒麟天地行，鳳凰開天際」" + NOR + "，舞出了月影微步\n的精義，$n身影輕輕地從$N的身邊飄過。\n",
"但見$n不慌不忙，左腳輕抬，一式" + HIM + "「天馬追月」" + NOR + "，$n的身影已出現在半空中，有如蝴\n蝶翩然起舞一般，輕輕的飄落在$N身影的一丈外。\n",
"月影微步的奧義，" + HIM + "「行者莫不住一腳，聽君輕唱仕女音」" + NOR + "，在$n的舞動下，有如一\n朵盛開的鮮花，鮮艷的彩蝶。\n"
});
 
int valid_skill_usage(string usage)
{
        return (usage=="dodge") || (usage=="move");
}
 int valid_enable(string usage)
 {
        return( usage=="dodge" || usage=="move") ;
 }
 
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 10 )
                return notify_fail("你的內力不夠﹐沒有辦法修鍊月影微步 .\n");
 
        return 1;
}
string perform_action_file(string action)
{
return CLASS_D("dancer")+"/paull-steps/"+action;
} 
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
 
int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的氣或內力不夠﹐不能練月影微步 .\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
