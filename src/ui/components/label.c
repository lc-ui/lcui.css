﻿/*
 * label.c -- Label component, which is used to represents a caption for an
 * item in a user interface.
 *
 * Copyright (c) 2018, Liu chao <lc-soft@live.cn> All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of LCUI nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/build.h>
#include <LCDesign/ui/components/label.h>

static struct LCDesign_LabelModule {
	LCUI_WidgetPrototype proto;
} self;

static void Label_OnClick(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCUI_Widget target = NULL;
	const char *target_id = Widget_GetAttribute(w, "for");

	if (target_id) {
		target = LCUIWidget_GetById(target_id);
	}
	if (target) {
		LCUIWidget_SetFocus(target);
	}
}

static void Label_Init(LCUI_Widget w)
{
	self.proto->proto->init(w);
	Widget_BindEvent(w, "click", Label_OnClick, NULL, NULL);
}

void LCDesign_InitLabel(void)
{
	self.proto = LCUIWidget_NewPrototype("label", "textview");
	self.proto->init = Label_Init;
}
