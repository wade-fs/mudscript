#include <ansi.h>
inherit NPC;
string *msg1=({
    "say 啊，你醒了!!!",
    "say 你昏迷了好久，我還怕你從此以後就這樣醒不來了!!",
    "say 真是太好了。",
    "say 你一定很想知道你為什麼會在(這裡)對吧!!",
    "action smile %s",
    "end",
});
string *msg2=({
    "say 慕容家族是我的殺父仇人。",
    "say 我恨他們入骨。",
    "say 我利用機會混入慕容家當婢女，主要就是為了復仇。",
    "say 那天你陷入慕容復佈下的陷阱，我正巧躲在一旁。",
    "say 是我丟了一顆煙霧彈，趁慕容小賊不注意的時候把你給救出來的。",
    "say 其實以你的功\力，應該不致於輸的那麼慘。",
    "say 正巧，我終於打聽到慕容小賊之所以會(無敵)的秘密了。",
    "say 要是你想知道的話，我可以告訴你。",
    "end",
});
string *msg3=({
    "say 啊，你醒了!!!",
    "say 你昏迷了好久，我還怕你從此以後就這樣醒不來了!!",
    "say 真是太好了。",
    "say 那天你走了之後，我又回到慕容家，當我的婢女。",
    "say 這麼好的一個身份，我可不想就此浪費。",
    "say 同時我想要親眼看到慕容小賊死在你的手上。",
    "say 沒想到你又輸了。",
    "say 這次被我重施故技，又救了你一次。",
    "say 下次你一定要做好準備再去，不然你如果又輸了，說不定我就救不到你了。",
    "action addoil %s",
    "say 全靠你了。",
    "end",
});

string do_here();
string do_woody();
string do_out();
int msg_steps;
void create()
{
        set_name("謎樣的少女",({"quest girl","girl"}));
        set("long",@LONG
她看起來十多歲, 正靜靜的趴在桌上睡覺, 你正覺得奇怪你怎會睡在這裡,
看來你可以試著把她叫起來(wakeup) 問問。
LONG);
        set("gender","女性");
        set("combat_exp", 1000);
        set("attitude","friendly");
        set("age",28);
        set("inquiry", ([
        "這裡" : (: do_here :),
        "無敵" : (: do_woody :),
        "出路" : (: do_out :),
        ]));
        set("force",5000);
        set("max_force",5000);
        set("kee",1000);
        set("max_kee",1000);
        set("force_factor",30);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("roared",1);
        setup();
}
void init()
{
    object ppl;

    ppl = this_player();
    add_action("do_wakeup","wakeup");
}
int do_wakeup(string arg)
{
    object ppl;

    ppl = this_player();
    if (!ppl) return 0;
//     tell_object(ppl,"wakeup command OK\n");
    if(!arg) return notify_fail("你要叫醒誰??\n");
    if(!id(arg)) return notify_fail("你要叫醒誰?\n");

    if(this_object()->query("wakeup"))
      return notify_fail("她已經醒了!!\n");
    message_vision("$N試著叫醒$n\n",this_player(),this_object());
    this_object()->set("long",@LONG
她剛被你叫醒, 一副睡眼惺鬆的樣子, 好像還沒睡飽的樣子, 你仔細一看, 才
發現她竟然是個大美人。
LONG);
    this_object()->set("per",45);
    this_object()->set("wakeup",1);
    message_vision("只見$N慢慢坐起身，雙眼無神的朝$n望去。\n",this_object(),this_player());
    ppl=this_player();
    if(!ppl->query("marks/kill_fu_fail"))
      call_out("do_msg1",4,ppl);
    else
      call_out("do_msg3",4,ppl);
    msg_steps=0;
    return 1;
}
int do_msg1(object ppl)
{
    int i;

    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;

    ppl->set("marks/kill_fu_fail",1);
    i=msg_steps;
    if(msg1[i][0..2]=="end"){
      msg_steps=0;
      return 1;
    }
    else if(msg1[i][0..2]=="msg"){
      message_vision(msg1[i][3..sizeof(msg1[i])-1],this_object(),ppl);
    }
    else if(msg1[i][0..5]=="action"){
      command(sprintf(msg1[i][7..sizeof(msg1[i])-1],geteuid(ppl)));
    }
    else{
      command(msg1[i]);
    }
    msg_steps+;
    call_out("do_msg1",4,ppl);
    return 1;
}
string do_here()
{
    if(!query("wakeup"))
    {
      message_vision("$N都還沒醒呢，先叫醒她再說吧!!\n",this_object());
      return "";
    }
    if(msg_steps) return "我正在講事情，你等一下再問。\n";
    command("say 既然你那麼想知道，我就來告訴你吧");
    call_out("do_msg2",4,this_player());
    return "";
}
int do_msg2(object ppl)
{
    int i;

    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;

    i=msg_steps;
    if(msg2[i][0..2]=="end"){
      msg_steps=0;
      return 1;
    }
    else if(msg2[i][0..2]=="msg"){
      message_vision(msg2[i][3..sizeof(msg2[i])-1],this_object(),ppl);
    }
    else if(msg2[i][0..5]=="action"){
      command(sprintf(msg2[i][7..sizeof(msg2[i])-1],geteuid(ppl)));
    }
    else{
      command(msg2[i]);
    }
    msg_steps+;
    call_out("do_msg2",4,ppl);
    return 1;
}
string do_woody()
{
    if(!query("wakeup"))
    {
      message_vision("她都還沒醒呢，先叫醒她再說吧!!\n",this_object());
      return "";
    }
    if(msg_steps) return "我正在講事情，你等一下再問。\n";
    if(this_player()->query("family/family_name")!="段家")
    {
      command("say 不過我告訴你也沒用，要破慕容小賊的無敵神功\");
      command("say 需要搭配段家的臨書點穴才辦得到。");
      return "";
    }
    if(this_player()->query("functions/handwriting/level")<100)
    {
      command("sigh");
      command("say 告訴你也沒用，你的臨書點穴等級還不夠。");
      command("say 最少也要到深不可測的等級，才有辦法破除慕容小賊的無敵神功\");
      return "";
    }
    command("say 看你的程度，學習這破解之法應該沒什麼問題了，就讓我來教你吧");
    command("say 聽好囉");
    command("say 如此如此，這般這般");
    message_vision(HIG + "$N對於$n所傳授的破解方法充份的了解了!!!\n" + NOR,
                   this_player(),this_object());
    command("say 你只要照我交給你的方法，配合你的臨書點穴之術，必可成功\");
    this_player()->set("marks/break_woody",1);
    command("say 加油，我在此等你的好消息了");
    return "";
}
int do_msg3(object ppl)
{
    int i;

    if(!ppl) return 1;
    if(environment(this_object()) != environment(ppl)) return 1;

    i=msg_steps;
    if(msg3[i][0..2]=="end"){
      msg_steps=0;
      return 1;
    }
    else if(msg3[i][0..2]=="msg"){
      message_vision(msg3[i][3..sizeof(msg3[i])-1],this_object(),ppl);
    }
    else if(msg3[i][0..5]=="action"){
      command(sprintf(msg3[i][7..sizeof(msg3[i])-1],geteuid(ppl)));
    }
    else{
      command(msg3[i]);
    }
    msg_steps+;
    call_out("do_msg3",4,ppl);
    return 1;
}
string do_out()
{
    if(!query("wakeup"))
    {
      message_vision("她都還沒醒呢，先叫醒她再說吧!!\n",this_object());
      return "";
    }
    if(msg_steps) return "我正在講事情，你等一下再問。\n";
    if(this_player()->query("marks/break_woody") != 1 && this_player()->query("functions/handwriting/level")>=100)
    {
      command("say 你就這麼想出去？");
      command("say 你都不想從我這邊知道些甚麼嗎？");
      return "";
    }
    command("say 顧著跟你說事情，都忘記這裡的出路只有我知道了");
    command(":P");
    command("say 馬上就送你出去");
    message_vision(HIG + "只見$N碰了一下身旁的牆壁，卡的一聲，一個出口出現了!!!\n" + NOR,
                   this_object());
    environment(this_object())->set("exits/out","/open/main/room/to_chun1");
    command("say 剛剛為了救你實在是太累了，我就不送囉");
    message_vision(HIG + "$N往後一躺，漸漸的睡著了\n" + NOR,
                   this_object());
    this_object()->set("per",25);
    set("long",@LONG
她看起來十多歲, 正靜靜的趴在桌上睡覺, 你正覺得奇怪你怎會睡在這裡,
看來你可以試著把她叫起來(wakeup) 問問。
LONG);
    this_object()->delete("wakeup");
    return "";
}
