// Protocol Buffers for Objective C
//
// Copyright 2010 Booyah Inc.
// Copyright 2008 Cyrus Najmabadi
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import "WireFormat.h"

@class BatPBCodedInputStream;
@class BatPBCodedOutputStream;
@class BatPBExtendableMessage_Builder;
@class BatPBExtensionRegistry;
@class BatPBUnknownFieldSet_Builder;

@protocol PBExtensionField
- (int32_t) fieldNumber;
- (PBWireFormat) wireType;
- (BOOL) isRepeated;
- (Class) extendedClass;
- (id) defaultValue;

- (void) mergeFromCodedInputStream:(BatPBCodedInputStream*) input
                     unknownFields:(BatPBUnknownFieldSet_Builder*) unknownFields
                 extensionRegistry:(BatPBExtensionRegistry*) extensionRegistry
                           builder:(BatPBExtendableMessage_Builder*) builder
                               tag:(int32_t) tag;
- (void) writeValue:(id) value includingTagToCodedOutputStream:(BatPBCodedOutputStream*) output;
- (int32_t) computeSerializedSizeIncludingTag:(id) value;
- (void) writeDescriptionOf:(id) value
                         to:(NSMutableString*) output
                 withIndent:(NSString*) indent;
@end
