/*$
 Copyright (C) 2013-2025 Azel.

 This file is part of AzPainter.

 AzPainter is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 AzPainter is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
$*/

/*****************************************
 * アプリケーション用カーソル
 *****************************************/

#include <mlk_gui.h>
#include <mlk_cursor.h>

#include "appcursor.h"


/*
 * - 各スロットに、必要なカーソルを作成してセット。
 *   同じスロットで同じカーソルが要求された場合は再作成せずに済む。
 * - 描画用矢印と砂時計カーソルは頻繁に使うので、初期化時に作成済み。
 */

//---------------------------

//描画
static const unsigned char g_cursor_draw[] = {
9,12, 0,0,
0x01, 0x00, 0x03, 0x00, 0x05, 0x00, 0x09, 0x00, 0x11, 0x00, 0x21, 0x00,
0x41, 0x00, 0x81, 0x00, 0xf9, 0x01, 0x05, 0x00, 0x03, 0x00, 0x01, 0x00,
0x01, 0x00, 0x03, 0x00, 0x07, 0x00, 0x0f, 0x00, 0x1f, 0x00, 0x3f, 0x00,
0x7f, 0x00, 0xff, 0x00, 0xff, 0x01, 0x07, 0x00, 0x03, 0x00, 0x01, 0x00 };

//回転
static const unsigned char g_cursor_rotate[] = {
21,25,0,0,
0x01,0x00,0x00,0x03,0x00,0x00,0x05,0x00,0x00,0x09,0x00,0x00,0x11,0x00,0x00,0x21,
0x00,0x00,0x41,0x00,0x00,0x81,0x00,0x00,0x01,0x01,0x00,0xf9,0x03,0x00,0x05,0x00,
0x00,0x03,0xf8,0x00,0x01,0xfe,0x03,0x00,0x06,0x07,0x00,0x00,0x06,0x00,0x00,0x0c,
0x00,0x01,0x0c,0x80,0x03,0x0c,0xc0,0x07,0x0c,0xe0,0x0f,0x0c,0x00,0x03,0x06,0x00,
0x07,0x07,0x00,0xfe,0x03,0x00,0xf8,0x00,0x00,0x00,0x00,
0x01,0x00,0x00,0x03,0x00,0x00,0x07,0x00,0x00,0x0f,0x00,0x00,0x1f,0x00,0x00,0x3f,
0x00,0x00,0x7f,0x00,0x00,0xff,0x00,0x00,0xff,0x01,0x00,0xff,0x03,0x00,0x07,0xf8,
0x00,0x03,0xfe,0x03,0x01,0xff,0x07,0x00,0xff,0x0f,0x00,0x06,0x0f,0x00,0x01,0x1e,
0x80,0x03,0x1e,0xc0,0x07,0x1e,0xe0,0x0f,0x1e,0xf0,0x1f,0x1e,0xe0,0x0f,0x0f,0x80,
0xff,0x0f,0x00,0xff,0x07,0x00,0xfe,0x03,0x00,0xf8,0x00 };

//スポイト
static const unsigned char g_cursor_spoit[] = {
14,14, 1,12,
0x00,0x00,0x00,0x0c,0x00,0x1e,0x80,0x1f,0xc0,0x0f,0xc0,0x07,
0x20,0x07,0x10,0x03,0x88,0x00,0x44,0x00,0x22,0x00,0x12,0x00,
0x0d,0x00,0x02,0x00,
0x00,0x0c,0x00,0x1e,0x80,0x3f,0xc0,0x3f,0xe0,0x1f,0xe0,0x0f,
0xe0,0x0f,0xf0,0x07,0xf8,0x03,0x7c,0x00,0x3e,0x00,0x1e,0x00,
0x0f,0x00,0x02,0x00 };

//選択
static const unsigned char g_cursor_select[] = {
17,21,0,0,
0x01,0x00,0x00,0x03,0x00,0x00,0x05,0x00,0x00,0x09,0x00,0x00,0x11,0x00,0x00,0x21,
0x00,0x00,0x41,0x00,0x00,0x81,0x00,0x00,0x01,0x01,0x00,0xf9,0x03,0x00,0x05,0x00,
0x00,0xc3,0xff,0x01,0x41,0x00,0x01,0x40,0x7f,0x01,0x40,0x41,0x01,0x40,0x41,0x01,
0x40,0x41,0x01,0x40,0x41,0x01,0x40,0x7f,0x01,0x40,0x00,0x01,0xc0,0xff,0x01,
0x01,0x00,0x00,0x03,0x00,0x00,0x07,0x00,0x00,0x0f,0x00,0x00,0x1f,0x00,0x00,0x3f,
0x00,0x00,0x7f,0x00,0x00,0xff,0x00,0x00,0xff,0x01,0x00,0xff,0x03,0x00,0x07,0x00,
0x00,0xc3,0xff,0x01,0xc1,0xff,0x01,0xc0,0xff,0x01,0xc0,0xc1,0x01,0xc0,0xc1,0x01,
0xc0,0xc1,0x01,0xc0,0xc1,0x01,0xc0,0xff,0x01,0xc0,0xff,0x01,0xc0,0xff,0x01 };

//範囲移動
static const unsigned char g_cursor_selmove[] = {
18,22,0,0,
0x01,0x00,0x00,0x03,0x00,0x00,0x05,0x00,0x00,0x09,0x00,0x00,0x11,0x00,0x00,0x21,
0x00,0x00,0x41,0x00,0x00,0x81,0x00,0x00,0x01,0x01,0x00,0xf9,0x03,0x00,0x05,0x00,
0x00,0x83,0xff,0x03,0x81,0x10,0x02,0x80,0x38,0x02,0x80,0x10,0x02,0x80,0x92,0x02,
0x80,0xff,0x03,0x80,0x92,0x02,0x80,0x10,0x02,0x80,0x38,0x02,0x80,0x10,0x02,0x80,
0xff,0x03,
0x01,0x00,0x00,0x03,0x00,0x00,0x07,0x00,0x00,0x0f,0x00,0x00,0x1f,0x00,0x00,0x3f,
0x00,0x00,0x7f,0x00,0x00,0xff,0x00,0x00,0xff,0x01,0x00,0xff,0x03,0x00,0x07,0x00,
0x00,0x83,0xff,0x03,0x81,0xff,0x03,0x80,0xff,0x03,0x80,0xff,0x03,0x80,0xff,0x03,
0x80,0xff,0x03,0x80,0xff,0x03,0x80,0xff,0x03,0x80,0xff,0x03,0x80,0xff,0x03,0x80,
0xff,0x03 };

//スタンプ
static const unsigned char g_cursor_stamp[] = {
15,21,0,0,
0x01,0x00,0x03,0x00,0x05,0x00,0x09,0x00,0x11,0x00,0x21,0x00,0x41,0x00,0x81,0x00,
0x01,0x01,0xf9,0x03,0x05,0x00,0x03,0x0f,0x01,0x09,0x00,0x09,0x00,0x0f,0x00,0x06,
0x00,0x06,0xe0,0x7f,0xe0,0x7f,0x20,0x40,0xe0,0x7f,
0x01,0x00,0x03,0x00,0x07,0x00,0x0f,0x00,0x1f,0x00,0x3f,0x00,0x7f,0x00,0xff,0x00,
0xff,0x01,0xff,0x03,0x07,0x00,0x03,0x0f,0x01,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x06,
0x00,0x06,0xe0,0x7f,0xe0,0x7f,0xe0,0x7f,0xe0,0x7f };

//上下ドラッグ拡大縮小
static const unsigned char g_cursor_zoom_drag[]={
16,16,5,5,
0xf8,0x00,0x04,0x01,0x22,0x02,0x71,0x04,0xf9,0x04,0x01,0x04,0xf9,0x04,0x71,0x04,
0x22,0x02,0x04,0x0d,0xf8,0x1e,0x00,0x3e,0x00,0x7c,0x00,0xf8,0x00,0xf0,0x00,0xe0,
0xf8,0x00,0xfc,0x01,0xfe,0x03,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,0xff,0x07,
0xfe,0x03,0xfc,0x0d,0xf8,0x1e,0x00,0x3e,0x00,0x7c,0x00,0xf8,0x00,0xf0,0x00,0xe0 };

//---------------------------

//スロット
enum
{
	SLOT_DRAW,		//描画用カーソル
	SLOT_WAIT,		//待ち
	SLOT_CANVAS,	//キャンバス用
	SLOT_DRAG,		//ドラッグ中用
	SLOT_DIALOG,	//ダイアログ用

	SLOT_NUM
};

static mCursor g_curslot[SLOT_NUM] = { 0,0,0,0,0 };

static int g_slot_no[SLOT_NUM] = { APPCURSOR_DRAW, APPCURSOR_WAIT, -1, -1, -1 };


//---------------------------


/* カーソル取得 */

static mCursor _get_cursor(int no)
{
	const char *name = NULL;
	const uint8_t *imgbuf = NULL;
	mCursor cur = 0;

	switch(no)
	{
		case APPCURSOR_HAND:
			name = "grab\0";
			break;
		case APPCURSOR_HAND_GRAB:
			name = "grabbing\0grab\0";
			break;
		case APPCURSOR_DND_ITEM:
		case APPCURSOR_MOVE:
			name = "dnd-move\0";
			break;

		case APPCURSOR_SELECT:
			imgbuf = g_cursor_select;
			break;
		case APPCURSOR_SEL_MOVE:
			imgbuf = g_cursor_selmove;
			break;
		case APPCURSOR_ROTATE:
			imgbuf = g_cursor_rotate;
			break;
		case APPCURSOR_ZOOM_DRAG:
			imgbuf = g_cursor_zoom_drag;
			break;
		case APPCURSOR_STAMP:
			imgbuf = g_cursor_stamp;
			break;
		//スポイト
		case APPCURSOR_SPOIT:
			name = "color-picker\0";
			imgbuf = g_cursor_spoit;
			break;

		case APPCURSOR_LEFT_TOP:
			name = "bd_double_arrow\0";
			break;
		case APPCURSOR_RIGHT_TOP:
			name = "fd_double_arrow\0";
			break;
		case APPCURSOR_RESIZE_HORZ:
			name = "h_double_arrow\0";
			break;
		case APPCURSOR_RESIZE_VERT:
			name = "v_double_arrow\0";
			break;
	}

	//カーソル名 (複数) から

	if(!cur && name)
		cur = mCursorLoad_names(name);

	//1bit イメージから
	
	if(!cur && imgbuf)
		cur = mCursorCreate1bit(imgbuf);

	return cur;
}

/* スロットからカーソル取得 */

static mCursor _get_cursor_slot(int slot,int cursorno)
{
	mCursor cur;

	if(g_slot_no[slot] == cursorno)
	{
		//現在のスロットに同じカーソルがある場合
		return g_curslot[slot];
	}
	else if(cursorno < 2)
	{
		//固定カーソルの場合
		return g_curslot[cursorno];
	}
	else
	{
		//スロットのカーソルを入れ替え
		
		mCursorFree(g_curslot[slot]);

		cur = _get_cursor(cursorno);

		g_slot_no[slot] = cursorno;
		g_curslot[slot] = cur;

		return cur;
	}
}


/** 初期化 */

void AppCursor_init(void)
{
	g_curslot[SLOT_DRAW] = mCursorCreate1bit(g_cursor_draw);
	g_curslot[SLOT_WAIT] = mCursorLoad("wait");
}

/** 終了時の解放 */

void AppCursor_free(void)
{
	int i;

	for(i = 0; i < SLOT_NUM; i++)
		mCursorFree(g_curslot[i]);
}

/** 描画用カーソルを変更
 *
 * filename: NULL または空文字列でデフォルト */

void AppCursor_setDrawCursor(const char *filename,int hotx,int hoty)
{
	mCursorFree(g_curslot[SLOT_DRAW]);

	g_curslot[SLOT_DRAW] = 0;

	//失敗時はデフォルトのカーソル

	if(filename && filename[0])
		g_curslot[SLOT_DRAW] = mCursorLoadFile_png(filename, hotx, hoty);

	if(!g_curslot[SLOT_DRAW])
		g_curslot[SLOT_DRAW] = mCursorCreate1bit(g_cursor_draw);
}

/** 待ち時用カーソル取得 */

mCursor AppCursor_getWaitCursor(void)
{
	return g_curslot[SLOT_WAIT];
}

/** キャンバス用のカーソル取得 */

mCursor AppCursor_getForCanvas(int no)
{
	return _get_cursor_slot(SLOT_CANVAS, no);
}

/** ドラッグ中用のカーソル取得 */

mCursor AppCursor_getForDrag(int no)
{
	return _get_cursor_slot(SLOT_DRAG, no);
}

/** ダイアログ用のカーソル取得 */

mCursor AppCursor_getForDialog(int no)
{
	return _get_cursor_slot(SLOT_DIALOG, no);
}

