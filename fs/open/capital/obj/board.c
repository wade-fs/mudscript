//p_human.c by chun 
			
inherit ITEM;

void create()
{
	set_name("公告欄",({"board"}) );
	set("long",@TEXT
	奉天承運  皇帝詔曰
	
	近日京城盜賊(thief)猖獗, 數戶大宅連續遭竊
	真為目無法紀, 特許懸賞五兩黃金與各路勇士,
	望能將此盜賊緝捕歸案, 若有意者請向京城總衙
	大人紀無塵詳問。

	欽此

TEXT);	
	set("no_get",1);
        setup();
}
