#include <ansi.h>
inherit F_FUNCTION;
int do_make_arrow(object me,int lv);
inherit SSERVER;
int perform(object me,object target)
{
int lv;
object ob;
me=this_player();
seteuid(getuid());

lv = me->query("functions/make_arrow/level");
if(me->query("force") < (lv * 3))return notify_fail("你的氣不夠,休息一下再用吧!!\n");
/*        if(objectp(ob = present("force arrow", me)))
                return notify_fail("你的箭已經夠了!!\n");*/
        if(me->is_busy()) return notify_fail("你正在忙喔!!\n");
        if(me->is_fighting()) me->start_busy(1);
message_vision(HIW"$N緊握著雙手，運氣一發勁，漸漸的手中出現了一道清煙!!\n"NOR,me);
me->start_call_out((:call_other,__FILE__,"do_make_arrow",me,lv:),2);
me->start_busy(1);
me->add("force",-(lv * 3));
if(me->query("force") < 0 ) me->set("force",0);
        return 1;
}
int do_make_arrow(object me,int lv)
{
object obj;
string element;
element = me->query("env/arrow_element");
if(!element || !me->query("break-sun")) element="none";
switch(element)
{
 case "fire":
 message_vision(HIR"焰靈逐漸在$N手上聚集，形成"+chinese_number(1+(lv*3))+"道箭氣。\n\n"NOR,me);
 obj=new("/open/marksman/break-sun/obj/fire-arrow");
 break;
 case "water":
 message_vision(HIC"凍氣逐漸在$N手上聚集，形成"+chinese_number(1+(lv*3))+"道箭氣。\n\n"NOR,me);
 obj=new("/open/marksman/break-sun/obj/water-arrow");
 break;
 case "gold":
 message_vision(HIY"金塵逐漸在$N手上聚集，形成"+chinese_number(1+(lv*3))+"道箭氣。\n\n"NOR,me);
 obj=new("/open/marksman/break-sun/obj/gold-arrow");
 break;
 case "wood":
 message_vision(HIG"木靈逐漸在$N手上聚集，形成"+chinese_number(1+(lv*3))+"道箭氣。\n\n"NOR,me);
 obj=new("/open/marksman/break-sun/obj/wood-arrow");
 break;
 case "soil":
 message_vision(YEL"岩屑逐漸在$N手上聚集，形成"+chinese_number(1+(lv*3))+"道箭氣。\n\n"NOR,me);
 obj=new("/open/marksman/break-sun/obj/soil-arrow");
 break;
 default:
 message_vision(HIY"一瞬間，"+chinese_number(1+(lv*3))+"道箭氣從$N手中飛越而出\n\n"NOR,me);
 obj=new("/daemon/class/marksman/iceforce/forcearrow.c");
 break;
}
obj->set_amount(1+(lv*3));
obj->move(me);
if(query_function("make_arrow") < 100)
              {
function_improved("make_arrow",random(500));
              }
return 1;
}

