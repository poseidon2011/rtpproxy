/*
 * Copyright (c) 2015 Sippy Software, Inc., http://www.sippysoft.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#if !defined(_RTPP_ANALYZER_H)
#define _RTPP_ANALYZER_H

struct rtpp_log;
struct rtp_packet;
struct rtpp_analyzer;
struct rtpp_refcnt;

#define SSRC_FMT "0x%.8X"

struct rtpp_analyzer_stats {
    unsigned long psent;
    unsigned long precvd;
    unsigned long plost;
    unsigned long pdups;
    unsigned long ssrc_changes;
    unsigned long pecount;
    unsigned long aecount;
    uint32_t last_ssrc;
};

struct rtpp_log;
struct rtp_packet;

DEFINE_METHOD(rtpp_analyzer, rtpp_analyzer_update, enum update_rtpp_stats_rval,
  struct rtp_packet *);
DEFINE_METHOD(rtpp_analyzer, rtpp_analyzer_get_stats, void,
  struct rtpp_analyzer_stats *);

struct rtpp_analyzer {
    METHOD_ENTRY(rtpp_analyzer_update, update);
    METHOD_ENTRY(rtpp_analyzer_get_stats, get_stats);
    struct rtpp_refcnt *rcnt;
};

struct rtpp_analyzer * rtpp_analyzer_ctor(struct rtpp_log *);

#endif
