//===-- stevemac::iterator.h --------------------------------------*- C -*-===//
//
// This file is distributed under the GNU General Public License, version 2
// (GPLv2). See https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html
// Author: Stephen E. MacKenzie
//===----------------------------------------------------------------------===//
#pragma once
#include <iterator>

namespace stevemac {
///===----------------------------------------------------------------------===//
///
/// \class stevemac::iterator
/// \brief Implementation started in fall of 2014. It is is derived from:
/// std::iterator<std::random_access_iterator_tag>.  It has only been tested
/// with stevemac::vector.
///
//===----------------------------------------------------------------------===//
/// Class Template stevemac::iterator
///
//===----------------------------------------------------------------------===//
template <typename Container>
class vector_iterator : public std::iterator<std::random_access_iterator_tag,
                                             typename Container::value_type> {
public:
  using value_type = typename Container::value_type;
  using pointer = typename Container::pointer;
  using reference = typename Container::reference;
  using difference_type = typename Container::size_type;

protected:
  /// pointee is owned by the Container
  ///
  pointer pointee;
  //===----------------------------------------------------------------------===//
  /// construct/destroy: The constructor is used for conversion
  /// The pointee member is owned and managed by the Container which is why
  /// iterator does not have any destruction duties
  //===----------------------------------------------------------------------===//

public:
  vector_iterator() {}
  /// explicit constructor used for converting to the underlying pointer type
  /// provided by the Container: Container::pointer.
    explicit  vector_iterator(const pointer ptr) : pointee(ptr) {}
  /// the Container owns the only resource: pointee; hence no duties here.
  ~vector_iterator() {}

  //===----------------------------------------------------------------------===//
  /// Operator overloads.
  ///
  //===----------------------------------------------------------------------===//

  reference operator*() { return *pointee; }
  pointer operator->() { return pointee; }

  vector_iterator &operator++() {
    ++pointee;
    return *this;
  }
  ///
  vector_iterator operator++(int) {
    vector_iterator tmp = *this;
    ++pointee;
    return tmp;
  }
  ///
  vector_iterator &operator--() {
    --pointee;
    return *this;
  }
  vector_iterator operator--(int) {
    vector_iterator tmp = *this;
    --pointee;
    return tmp;
  }
  
  difference_type operator-(vector_iterator &other) {
    return pointee - other.pointee;
  }
  vector_iterator operator+(difference_type n) {
    return vector_iterator(pointee + n);
  }
  vector_iterator operator-(difference_type n) {
    return vector_iterator(pointee - n);
  }
  vector_iterator &operator+=(difference_type n) {
    pointee += n;
    return *this;
  }
  vector_iterator &operator-=(difference_type n) {
    pointee -= n;
    return *this;
  }

  //===----------------------------------------------------------------------===//
  /// logical operators
  ///
  //===----------------------------------------------------------------------===//
  bool operator==(const vector_iterator &other) const {
    return pointee == other.pointee;
  }

  bool operator!=(const vector_iterator &other) const {
    return pointee != other.pointee;
  }

  bool operator<(const vector_iterator &other) {
    return pointee < other.pointee;
  }

  bool operator>(const vector_iterator &other) {
    return pointee > other.pointee;
  }

  bool operator<=(const vector_iterator &other) {
    return pointee <= other.pointee;
  }

  bool operator>=(const vector_iterator &other) {
    return pointee >= other.pointee;
  }
};
} // end stevemac
