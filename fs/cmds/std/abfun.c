// abandon.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        int flv,fld;
        flv=me->query("functions/"+arg+"/level");
        fld=me->query("functions/"+arg+"/learned");
	if( !arg ) return notify_fail("你要放棄哪一項特攻﹖\n");

        if (!me->query("functions/"+arg) )
	return notify_fail("你並沒有這項特攻。\n");
        me->delete("functions/"+arg+"/level",flv);
        me->delete("functions/"+arg+"/learned",fld);
        me->delete("functions/"+arg);
	write("你決定放棄" + to_chinese(arg) + "此項特攻。\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式﹕abfun <技能名稱>

放棄一項你所學的技能，注意這裡所說的「放棄」是指將這項技能從你人物的資料中
刪除，如果你以後還要練，這就愛莫能助了.

這個指令使用的場合通常是用來刪除一些「不小心」練出來的技能，由於我們假設你
的人物隨時都會從他／她的各種動作、戰鬥中學習，因此有些技能會因為你經常地使
用而出現在你的技能列表中，這個人物就必須花費一些精神去「記住」所學過的一切
，然而，人的資質各有不同，靈性高的人能夠學習許多技能而成為多才多藝的才子，
靈性較差的人就只能專心於特定幾項技能，如果你學的技能種類太多，超過你的靈性
，你會發現人物的學習速度將比只學幾種技能的人慢，超過越多，學習效果低落的情
況越嚴重，這種情形就像是一個學期同時選修太多學分，雖然你仍然可以憑著超人的
意志力練下去，不過這將會多花費你許多寶貴的時間。

  注意: 如果一旦放棄了某項技能, 將無法再學回來.
TEXT
	);
	return 1;
}
