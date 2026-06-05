//新渾天寶鑑
//修正 by swy
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP; 
void remove_effect(object me, int skill);
int perform(object me, object target)
{
        string env;
        int skill,fun1;
        skill=me->query_skill("superforce",1);
        env=me->query("env/superforce");
        if(me->query("class")!="prayer"&&me->query("id")!="swy")
        return notify_fail("非聖火不能用。\n");   
        if(env=="YES"||(env!="white"&&env!="gen"&&env!="ice"&&env!="purple"&&env!="nine"
           &&env!="black"&&env!="bluesea"&&env!="goldsun"&&env!="blood"&&env!="green"))
        return notify_fail("你要運哪一種心法呢。\n");   
        if( (string)me->query_skill_mapped("force")!= "superforce" )
        return notify_fail("渾天心法氣勁要用渾天心法來運作。\n");    
        if( skill<20 )
        return notify_fail("你渾天心法等級不夠最少要 20。\n");    
        if (me->query("force") < 300)
        return notify_fail("你的內力不夠，不能運起渾天心法。\n");
        if(me->query_temp("mixforce")==1)
        return notify_fail("你已經在使用渾天心法。\n");
        if( skill>=250 ) skill=250;
        me->add("force",-250);
if (skill >= 20 && env=="white") {
        fun1=me->query("functions/white/level");
        if(!fun1) me->set("functions/white/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第一層的" + HIW + "白雲煙" + HIC + "﹐身上湧出如雲氣般的內勁形成無數的氣旋!!\n" + NOR,me);
        me->set_temp("superforce",1);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1); 
        } else 
if (skill >=30 && env=="nine") {
        fun1=me->query("functions/nine/level");
        if(!fun1) me->set("functions/nine/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第二層的" + CYN + "玫蕩霞" + HIC + "﹐身上發出如晚霞般的光茫形成無數的氣流!!\n" + NOR,me);       
        me->set_temp("superforce",2);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >= 40 && env=="gen") {
        fun1=me->query("functions/gen/level");
        if(!fun1) me->set("functions/gen/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第三層的" + YEL + "土崑崙" + HIC + "﹐身上發出如大地般的迫力,形成無數的氣流!!\n" + NOR,me);
        me->set_temp("superforce",3);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=50 && env=="ice") {
        fun1=me->query("functions/ice/level");
        if(!fun1) me->set("functions/ice/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第四層的" + HIW + "碧雪冰" + HIC + "﹐身上發出如寒霜般的寒勁,四周的空氣似乎也為之凍結!!\n" + NOR,me);
        me->set_temp("superforce",4);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=60 && env=="purple") {
        fun1=me->query("functions/purple/level");
        if(!fun1) me->set("functions/purple/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第五層的" + MAG + "紫星河" + HIC + "﹐臉色紫氣大盛!!全身湧出如星河般的內勁!!\n" + NOR,me);
        me->set_temp("superforce",5);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=80 && env=="black") {
        fun1=me->query("functions/black/level");
        if(!fun1) me->set("functions/black/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第六層玄混沌﹐面泛黑氣﹐全身的內勁增加了有數倍之多!!\n" + NOR,me);
        me->set_temp("superforce",6);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=110 && env=="bluesea") {
        fun1=me->query("functions/bluesea/level");
        if(!fun1) me->set("functions/bluesea/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第七層" + HIB + "[靛滄海]" + HIC + "﹐真氣流竄﹐暮地周圍出現" + HIB + "海嘯般的內勁" + HIB + "!!\n" + NOR,me);
        me->set_temp("superforce",7);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=150 && env=="goldsun") {
        fun1=me->query("functions/goldsun/level");
        if(!fun1) me->set("functions/goldsun/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第八層" + HIY + "[金晨曦]" + HIC + "﹐真氣鼓漲﹐剎時全身爆出" + HIY + "萬道金色的光芒" + NOR + "!!\n" + NOR,me);
        me->set_temp("superforce",8);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else 
if (skill >=200 && env=="blood") {
        fun1=me->query("functions/blood/level");
        if(!fun1) me->set("functions/blood/level",1);
        skill=(int)skill/5;
        message_vision(
        HIC + "$N運起渾天心法第九層" + HIR + "[血穹蒼]" + HIC + "﹐將真氣運佈全身﹐剎時全身冒出血紅色的蒸氣!!\n" + NOR,me);
        me->set_temp("superforce",9);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        } else {
if (skill >=250 && env=="green") {
        fun1=me->query("functions/green/level");
        if(!fun1) me->set("functions/green/level",1);
        skill=(int)skill/5;
        message_vision(

HIC + "$N運起渾天心法最終層" + HIG + "[玄宇宙]" + HIC + "，剎時天空昏暗，萬星繁動，全身經脈充滿了星晨所付予的氣勁!!\n" + NOR,me);
        me->set_temp("superforce",10);
        me->set_temp("mixforce",1);
        me->add_temp("apply/force",   skill);
        me->add_temp("apply/move",    skill);
        me->add_temp("apply/dodge",   skill);
        me->add_temp("apply/unarmed", skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill*2);
        if( me->is_fighting() ) me->start_busy(1);
        }
        }
        if(!me->query_temp("mixforce")) {
        message_vision(HIW + "$N渾天心法等級不夠再運也沒有用!\n" + NOR,me); }        
        return 1;
}
 
void remove_effect(object me, int skill)
{
        int fun,lv;
        lv=me->query_temp("superforce");
if(lv==1) {
fun=me->query("functions/white/level");
if(fun<50)
function_improved("white",1000);
} else if(lv==2) {
fun=me->query("functions/nine/level");
if(fun<50)
function_improved("nine",1000);
} else if(lv==3) {
fun=me->query("functions/gen/level");
if(fun<50)
function_improved("gen",1000);
} else if(lv==4) {
fun=me->query("functions/ice/level");
if(fun<50)
function_improved("ice",1000);
} else if(lv==5) {
fun=me->query("functions/purple/level");
if(fun<50)
function_improved("purple",1000);
} else if(lv==6) {
fun=me->query("functions/black/level");
if(fun<100)
function_improved("black",900);
} else if(lv==7) {
fun=me->query("functions/bluesea/level");
if(fun<100)
function_improved("bluesea",800);
} else if(lv==8) {
fun=me->query("functions/goldsun/level");
if(fun<150)
function_improved("goldsun",700);
} else if(lv==9) {
fun=me->query("functions/blood/level");
if(fun<150)
function_improved("blood",600);
} else {
fun=me->query("functions/green/level");
if(fun<150)
function_improved("green",500);
}
        me->add_temp("apply/force",    -skill);
        me->add_temp("apply/unarmed",  -skill);
        me->add_temp("apply/move",     -skill);
        me->add_temp("apply/dodge",    -skill);
        me->delete_temp("mixforce");
        me->delete_temp("superforce");
        message_vision(HIW + "$N的渾天心法氣勁開始渙散了。\n" + NOR,me);
}
