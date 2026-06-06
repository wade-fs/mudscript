// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
  set ("short", "藏經閣門口");
	set( "build", 180 );
  set ("long", @LONG
這是藏經閣的門口，你看到門前一個碩大的匾額(sign)，上邊以楷書
寫著〔藏經閣〕三個大字，在門口的兩側有著兩座栩栩如生的雕像，似乎
直盯著你看。
 
LONG);

 set("outdoors","/open/gsword/room");
  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/gsword/room/g5-12.c",
  "southwest" : "/open/gsword/room/g5-10.c",
]));

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "            ,,   ;;                                               ,,, 
          ';;  ,,;,,,;;        ,,,                   ,,,;';,  ;;'''';;
      ;;;'';;   ;  ,,          ;;     ;;;;''''       ;; ,,;;   ;,;' ;;
                ;;  ';        ;' ;;, ,   ,,  ;,       ;'' ;;   ; ,,,;;
     ,  ,,,,,,;';;''        ,;' ,;'  ;; ;;' ;'        ;,;'';;,,'''  ;;
     ;;  ; ,,,,,,;,  ,     ';'';'   ;' ,;  ';,,       ;   ,;'';;    ;;
     ;;''; ;';;  '; ,;'      ,;',;, ';, ';   ''       ;  ' ';;;     ;;
        ,; ;''';; ;;;'      ;;;'' '   ' ,,,,,,        ;   ,;' ';,,  ;;
   '';;';' ;,,,'   ;;         ,  ;, '''';;''         ,; ,';,,,;;;''';;
     ;' ;  ; ;,,, ;';;,  ,';, ';  '     ;;  ,,,,     ;;   ;;  ,;',,,;;
   ,'  ;' ''    ;;'  ';,;; ';     ,,;'''''''''''''   ';    ;''''  ';;;
",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/swordsman/chenun" :1,
]));

  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="east" && present("chen un",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("張乘雲說道: 掌門有令,欲入藏經閣者,需得到他的同意,"
+RANK_D->query_respect(me)+"還是請回吧!\n");
return ::valid_leave(me,dir);
}
