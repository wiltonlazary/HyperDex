// Copyright (c) 2012, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of HyperDex nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef append_only_log_segment_list_h_
#define append_only_log_segment_list_h_

// STL
#include <utility>

// append only log
#include "append_only_log.h"
#include "append_only_log_constants.h"
#include "append_only_log_segment.h"
#include "append_only_log_writable_segment.h"

class hyperdex::append_only_log::segment_list
{
    public:
        segment_list();
        ~segment_list() throw ();

    public:
        e::intrusive_ptr<segment_list> add(uint64_t lower_bound, writable_segment* ws);
        uint64_t get_lower_bound(size_t i);
        segment* get_segment(size_t i);
        bool sync(size_t i);

    private:
        friend class e::intrusive_ptr<segment_list>;

    private:
        segment_list(const segment_list&);

    private:
        void inc();
        void dec();

    private:
        segment_list& operator = (const segment_list&);

    private:
        size_t m_ref;
        size_t m_sz;
        std::pair<uint64_t, e::intrusive_ptr<segment> >* m_segments;
};

#endif // append_only_log_segment_list_h_
