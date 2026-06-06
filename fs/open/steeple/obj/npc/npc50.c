#include <ansi.h>
#include "/open/open.h" 
inherit NPC;
void create()
{
        set_name("獨孤嵊",({"degu sa","sa"}));
        set("long","此人是獨孤愁的師兄，和弟子獨孤莫愁一心想平魔刀。\n");
        set("gender","男性");
        set("combat_exp",20000000);
        set("score",9000000);
        set("sec_kee","god");
        set("max_s_kee",1000);
        set("s_kee",1000);
        set("age",60);
        set("class","fighter");
        set("family/family_name","雪蒼派");
        set("quests/read_snow",3);
        set("title",HIW + "～幻影～" + NOR + "武天至聖");
        set("force",4500000);
        set("max_gin",200000);
        set("max_kee",500000);
        set("max_sen",200000);
        set("bellicosity",10000);
        set("max_force",5000000);
        set("force_factor",80);
        set("str",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("con",50);
        set("spi",50);
        set("no_hole",1);
        set("no_plan_follow",1);
        set("no_mount",1);
        set("functions/kang-power/level",150);
set("chat_chance_combat",10);
set("chat_msg_combat",({
(: perform_action, "force.kang_kee" :),
}));
        set_skill("snow-martial", 150);
        set_skill("snowforce", 300);
        set_skill("literate",150);
        set_skill("black-steps",150);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("snow-kee",150);
        set_skill("parry",150);
        set_skill("force",150);
        map_skill("unarmed", "snow-martial");
        map_skill("parry","snow-kee");
        map_skill("force", "snowforce");
        map_skill("dodge", "black-steps");
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        setup();
        carry_object("/open/snow/obj/figring")->wield();
        add_money("cash", 1);
}
void init()
{
add_action("do_cmd","cmd");
}
int do_cmd(string str) {
 object who=this_player();
if(str=="throw five poison to sa" ||
   str=="throw five poison to degu sa") {
return 0;
} else 
 if(str=="askgod sa" || str=="askgod degu sa") {
 command("say 本武聖最厭惡使用占卜指令的人了，送死吧！\n");
 who->start_busy(2);
 kill_ob(who);
} else if(str=="bak sa" || str=="bak degu sa") {
  command("say 本武聖一生光明最厭惡偷偷摸摸的人了，送死吧！\n");
  who->start_busy(2);
  kill_ob(who);
}
 return 1;
}

void heart_beat()
{
object winner = query_temp("last_damage_from");  
object me,room,*target,victim,*player;
int i,j,k,a,b,c,d=0,f=0;
a=random(100);
me=this_object();
room=environment(me);
target=me->query_enemy(room); 
if(i=sizeof(target)) {
player=me->query_enemy(room);
for(c=0;c<i;c++) {
if(!userp(target[c])) continue;
player[d]=target[c]; 
d=d+1;
f=f+1;
}
if(a <= 10) {
victim=player[random(f)];
if(environment(me)==environment(victim)) {
for(k=0;k<10;k++) {
message_vision(HIG + "獨孤嵊大喝一聲，融合雪蒼與瀧山絕學，向$N擊出『玄冰離火掌』\n" + NOR,victim);
victim->add("kee",-3000);
COMBAT_D->report_status(victim);
}
victim->set_temp("last_damage_from",me);
victim->die();
}
}
if(a>=50&&a<=75) {
message_vision(HIW + "

獨孤嵊突然眼露兇光，周圍聚集陰冷內勁 

" + HIR + "獨孤嵊邪惡的狂吼：看我的『滅屍溶血掌』 

" + HIB + "頓時一股強烈的屍臭味瀰天而生隴罩四周圍 

" + NOR,me);
for(b=0;b<i;b++) {
if(userp(target[b])) continue;
target[b]->die();
}
}
}
if((me->query("eff_kee") < 4000 || me->query("kee") < 4000) &&
!me->query("change"))
{
tell_object(me,"");
tell_object(me,HIR + "\n可惡呀！獨孤嵊怒道：老虎不發威，你當病貓！\n\n看來我只好使出百分之二百的力量了！\n\n可恨的"+me->query("name")+"等死吧！\n\n");
tell_object(me,"");
        me->set("force_factor",40);
        me->set("eff_kee",200000);
        me->set("kee",200000);
        me->set("eff_gin",50000);
        me->set("eff_sen",50000);
        me->set("gin",50000);
        me->set("sen",50000);
        me->set("force",500000);
        me->set("fire_strike",1);
        me->set("super_fire",1);
        me->set("family/family_name","瀧山派");
        me->set("env/瀧山連擊","YES");
        me->set("combat_exp",20000000);
        me->set_skill("lungshan", 150);
        me->set_skill("haoforce", 300);
        me->set_skill("fire-kee",150);
        me->set_temp("kang-power",1);
        map_skill("unarmed", "lungshan");
        map_skill("parry","fire-kee");
        map_skill("force", "haoforce");
        me->reset_action();
        me->set("change",1);
        me->delete_busy();
        me->clear_condition();
        me->set("nickname",HIW + "～幻影～" + HIC + "『綻藍聖光』"+HIW+"武天至聖" + NOR);
}
if(i=sizeof(target)) {
if(random(100) > 27)
{
if(!me->query("change"))
{
if(random(10) >= 5)
{
message_vision(HIY + "獨孤嵊運起『離火掌』向你一擊，頓時你鮮血狂噴！\n" + NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-3000);
target[j]->apply_condition("hart",5);
}
} else {
message_vision(HIC + "獨孤嵊心感疲狽，運起『獨孤秘傳法咒』一道藍光從蒼天發出，頓時精神百倍。\n" + NOR,me);
if(random(10) >= 5) {
me->receive_curing("kee",10000);
me->receive_heal("kee",10000);
}
    me->add("force",10000);
    me->delete_busy();
    me->clear_condition();
}
} else {
if(random(10) >= 5) {
message_vision(HIB + "

獨孤嵊運起雪蒼寒勁，頓時只見獨孤嵊藍光護身，霎似天神！
" + HIY + "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆

" + HIR + "獨孤嵊怒吼：看我的『綻藍光體術』！！！

" + HIY + "※※※※※※※※※※※※※※※※※※※
" + HIB + "頓時一陣強烈的藍光似猛虎似的把你吞沒在口中！


" + NOR,me);
for(j=0;j < i;j++) {
target[j]->add("kee",-5000);
}} else {
message_vision(HIC + "獨孤嵊心感疲狽，運起『綻藍光體術』一道藍光從蒼天發出，頓時精神百倍。\n" + NOR,me);
if(random(10) >= 5) {
me->receive_curing("kee",5000);
me->receive_heal("kee",5000);
}
me->delete_busy();
me->add("force",10000);
me->clear_condition();
}
}
}
}
::heart_beat();
}

int heal_up()
{
        if (!is_fighting() ) {
             message_vision (HIW + "系統：戰鬥停止，$N回收中，。\n" + NOR, this_object ());
             destruct(this_object());
             return 1;
        }
        return ::heal_up() + 1;
}
void unconcious ()
{
 object me=query_temp("last_damage_from");
if(!present("fight_card",me))
{
tell_object(me,"\n\n系統：由於你沒攜帶晶片，所以無法記錄戰績。\n");
destruct (this_object ());
}
else
if(!me->query("quest/start_game"))
{
tell_object(me,"\n\n系統：由於你沒有正式登記，資料無法傳輸。\n");
destruct (this_object ());
}
else
if(me->query("quest/start_game")< 51)
       {
        tell_object(users(),HIY + "
恭喜"HIW+me->query("name")+HIY"挑戰" + HIG + "『" + HIR + "第五十層試煉ソ塔" + HIG + "』" + HIY + "通過！！

期望"HIW+me->query("name")+HIY"也能在" + HIG + "『" + HIW + "天ソ閣" + HIG + "』" + HIY + "創下佳績。
	" + NOR);
	me->set("quest/start_game",51);
        destruct (this_object ());
       }
{
        :: unconcious();
	tell_object(me,HIW + "系統：你已經通過測試，系統不做任何更改。\n" + NOR);
	destruct(this_object());
}
}
