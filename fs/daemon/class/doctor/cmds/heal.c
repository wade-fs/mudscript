#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int main(object me, string arg)
{
    object ob;
    int sk, sk2;
    sk = (int)me->query_skill("cure",1);
    sk2 = (int)me->query_skill("godcure",1);    
    if(!me) return 1;
    if(!arg) return notify_fail("指令格式：cmd heal <id>\n");
    if(environment(me)->query("no_kill") == 1)
    return notify_fail("此地不適合醫生看診唷！\n");
    if(me->query("family/family_name") != "銀針門" && !wizardp(me))
    return notify_fail("你不是個醫生，怎麼能幫人看診？\n");
    if(sk < 120) return notify_fail("你的醫術不夠，尚無資格幫人看診！\n");
    if(sk2 < 100) return notify_fail("你的華佗醫術不夠，尚無資格幫人看診！\n");
    if(!me->query("doctor/vet")) return notify_fail("你還沒有經過華佗的認證唷！\n");
    if(me->query("gin") < 500) return notify_fail("你的精力不足，沒有辦法幫人看診！\n");
    if(me->query("sen") < 500) return notify_fail("你的神瞑不足，沒有辦法幫人看診！\n");
    if(me->is_fighting() || me->is_busy()) return notify_fail("你還是先把手邊的事忙完吧！\n");
    arg = lower_case(arg);
    ob = present(arg, environment(me));
    if(!objectp(ob)) return notify_fail("你想要看診哪位病人啊？\n");
    if(!ob->is_character()) return notify_fail("你只能幫人看診好不好！\n");
    if(ob->is_corpse()) return notify_fail("現在才要幫他看診療...太遲了些吧？\n");
    message_vision(HIW"$N抓著$n的手，聚精會神的為$n把把脈，開始看診了起來！\n"NOR,me, ob);
    if(ob->query_temp("over/right")&&ob->query_temp("over/left")) {
        message_vision(HIC"原來$N雙手受傷，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/right");
        ob->delete_temp("over/left");
        ob->delete_temp("hand-all");
        } else if(ob->query_temp("over/r-eyes")&&ob->query_temp("over/l-eyes")) {
        message_vision(HIC"原來$N雙目失明，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/r-eyes");
        ob->delete_temp("over/l-eyes");
        ob->delete_temp("eyes-all");
        } else if(ob->query_temp("over/left")) {
        message_vision(HIC"原來$N左手受傷，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/left");
        } else if(ob->query_temp("over/right")) {
        message_vision(HIC"原來$N右手受傷，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/right");
        } else if(ob->query_temp("over/r-eyes")) {
        message_vision(HIC"原來$N右眼失明，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/r-eyes");
        } else if(ob->query_temp("over/l-eyes")) {
        message_vision(HIC"原來$N左眼失明，還好我這有藥膏，擦擦就沒事了!\n"NOR,ob);
        ob->delete_temp("over/l-eyes");
        } else {
        message_vision(HIW"$N身體很健健康康沒有生病!\n"NOR,ob);
        }
    me->receive_damage("gin",500);
    me->receive_damage("sen",500);
    return 1;
}
int help(object me)
{
        write(@HELP
指令格式：cmd heal <id>
指令說明：
　　　       醫生專為眼睛失明雙手受傷的醫療！
HELP);
        return 1;
}

