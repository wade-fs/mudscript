inherit NPC;

int *a=({0, 0, 0, 0, 0, 0});
int *b=({0, 0, 0, 0, 0, 0});
int in_toss;

void create()
{
        set_name("孤魂野鬼", ({ "ghost" }) );
        set("gender", "男性" );
        set("age", 50);
        set("int", 30);
        set("long","一個落單的野鬼，路過的鬼卒都跟他打招呼，好像人面很熟，搞不好可以從他口中探到不少消息，但是他眼中充滿貪婪的眼神，彷彿前世十分好賭。\n" );
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);                        
        set("attitude", "peaceful");
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
}

void init()
{
        add_action("reply", "ask");
        add_action("do_beg", "beg");
        add_action("do_kneeze", "kneeze");
        add_action("do_play","play");
        add_action("do_toss","toss");
}

int reply(string str)
{
int i;

    i = this_player()->query_temp("ask");
    if(i == 0)
        write("我在這一帶還算蠻熟的，應該算是奈何橋的地頭蛇吧！\n");
    else if (i == 1)
        write("我認識很多出名的人喔！如果不想受酷刑的話就來求(beg)我吧！\n");
    else if (i >= 2) {
        write("我就是因為好賭，而欠債累累，最後被放高利貸砍死的。不過近來技術進步了，不少鬼差兄弟還欠我錢咧！\n");
        return 1;
    }
    if (this_player()->query_tmp("death/quest"))
        write("聽說奈何橋下有一條小徑通到河邊，而且有不少好東西在那裡。\n");

    this_player()->set_temp("ask", ++i);
    return 1;
}

int do_beg(string str)
{
        if (str != "ghost")
                return notify_fail("你要求誰啊！？\n");
        else if(this_player()->query_temp("death/dice"))
                return notify_fail("你已經跟我玩過一次了！不要貪心再來煩我！！\n");
        else {
            if(this_player()->query_temp("ask") < 3)
                return notify_fail("你要求我嗎？先跪(kneeze)下來再求一次吧！\n");
            else {
                write("好吧！看你這麼有誠意，就跟你玩(play)一盤吧！玩贏我再幫你說情。\n");
                this_player()->set_temp("ask", 4);
                return 1;
            }
        }
}

int do_kneeze(string str)
{
        if(str != "ghost")
                return notify_fail("你要向誰跪下啊！？\n");
        else
        {
            if(this_player()->query_temp("ask")>=3)
                return notify_fail("你已經跪下來了！\n");
            else {
                message_vision("$N一臉委屈地朝孤魂野鬼跪了下去。\n", this_player());
                this_player()->set_temp("ask", 3);
                return 1;
            }
        }
}


int do_play(string str)
{
        if(this_player()->query_temp("ask")<4)
                return notify_fail("本大爺不屑跟你玩！先求我吧！\n");
        else
        {
        if(this_player()->query_temp("death/force"))
                write("孤魂野鬼說道：來吧，請擲(toss)骰子(dice)！\n              如果你擲的比我大，那你就不用扣內力了！\n              但是你只有一次的機會喔！\n");
        else if(this_player()->query_temp("death/mana"))
                write("孤魂野鬼說道：來吧，請擲(toss)骰子(dice)！\n              如果你擲的比我大，那你就不用扣法力了！\n              但是你只有一次的機會喔！\n");
        else if(this_player()->query_temp("death/atman"))
                write("孤魂野鬼說道：來吧，請擲(toss)骰子(dice)！\n              如果你擲的比我大，那你就不用扣靈力了！\n              但是你只有一次的機會喔！\n");
        else
        {
                write("孤魂野鬼說道：啊！對不起！我突然發現我不能幫上你的忙！請你去找別人吧！\n");
                this_player()->delete_temp("ask");
        }
        }
        this_player()->set_temp("ask", 5);
        return 1;
}

int do_toss(string str)
{
        int i;

        if( str!="dice") 
                return notify_fail("你要玩什麼？\n");
/*      if(this_player()->query_temp("ask")!=5)
                return notify_fail("本大爺不屑跟你玩！先求我吧！\n");*/
        if(this_player()->query_temp("death/dice"))
                return notify_fail("你已經跟我玩過一次了！不要貪心再來煩我！！\n");
        if(this_player()->query_temp("death/force"))
                return notify_fail("我不能幫你任何忙！請你不要煩我了！\n");
        if( in_toss )
                return notify_fail("我正在跟別人玩，不要打攪我們！！\n");
        in_toss=1;
        this_player()->set_temp("ask", 6);
        for(i=0;i<3;i++)
        {
                a[i]=random(6)+1;
                a[i+3]=0;
                b[i]=random(6)+1;
                b[i+3]=0;
        }
        a[3]=a[0]+a[1]+a[2];
        b[3]=b[0]+b[1]+b[2];

        if(a[1]==a[2] && a[0]==a[1])
                a[5]=a[1];
        else if(a[1]==a[2] || a[0]==a[1])
                a[4]=a[1];
        else if(a[0]==a[1] || a[0]==a[2])
                a[4]=a[0];
        else if(a[1]==a[2] || a[0]==a[2])
                a[4]=a[2];
        else
                a[4]=0;
                
        if(b[1]==b[2] && b[0]==b[1])
                b[5]=b[1];
        else if(b[1]==b[2] || b[0]==b[1])
                b[4]=b[1];
        else if(b[0]==b[1] || b[0]==b[2])
                b[4]=b[0];
        else if(b[1]==b[2] || b[0]==b[2])
                b[4]=b[2];
        else
                b[4]=0;
        message_vision("$N大喊︰上天可憐可憐我吧！來個豹\子吧！\n$N親了一下手中的骰子，慎重的往碗公裡甩去．．\n", this_player());
        call_out("roll_dice", 2, 0, this_player()->query("id"));
        return 1;
}

void roll_dice(int i, string ppl)
{
        if(i<3)
        {
        say("骰子在碗公裡滾了一會兒．．終於第"+chinese_number(i+1)+"個骰子停了下來，是"+chinese_number(a[i])+"點。\n");
        call_out("roll_dice", 2, i+1, ppl);
        } else {
        if(a[5] > 0)
        say("\n野鬼說道：看來要使出絕活才能贏你了！看我的！\n");
        else if(a[4] > 0)
        say("\n野鬼說道：好小子！看不出來你的技術不錯嘛！！現在換我了！\n");
        else
        say("\n野鬼說道：哈！哈！哈！不過如此爾爾，看我怎麼痛宰你！\n");
        say("\n野鬼一把抓起骰子，好像作法般亂舞起來，接著大喊一聲：西八辣！！熟練地把手中的骰子如雨點般往碗公裡甩去。\n\n");
        call_out("ghost_turn", 3, 0, ppl);
        }
}

int ghost_turn(int i, string ppl)
{
object ob;

        if(i<3)
        {
        say("骰子在碗公裡翻騰了一陣子．．野鬼大喝一聲：停！\n骰子好像會聽話似的停了下來，第"+chinese_number(i+1)+"顆的點數是"+chinese_number(b[i])+"。\n");
        call_out("ghost_turn", 2, i+1, ppl);
        } else {
        in_toss=0;
        ob=find_player(ppl);
        ob->set_temp("death/dice", 1);
        ob->delete_temp("ask");
        if(a[5] == b[5] && a[4]==b[4] && a[3] == b[3]) {
                ob->delete_temp("death/dice");
                ob->set_temp("ask", 5);
                say("\n野鬼說道：這次平手，再來一次！\n");
                return 1;
        } else if(a[5] < b[5] ) {
                say("\n野鬼說道：哈哈哈！你不是我的對手啦！\n");
                return 1;
        } else if(a[4] < b[4]) {
                say("\n野鬼說道：怎樣？我很強吧！下次再來吧！\n");
                return 1;
        } else if(a[3] < b[3]) {
                say("\n野鬼說道：不服氣再來啊！我隨時奉陪！\n");
        } else {
        say("\n野鬼說道：你果真有兩把刷子，我再去練幾把，再等你來賜教！！\n");
        ob->delete_temp("death/force");
        ob->delete_temp("death/mana");
        ob->delete_temp("death/atman");
        return 1;
        }
        }
}

