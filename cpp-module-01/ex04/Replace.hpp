/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:19:20 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/29 13:19:22 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Replace {
 public:
  Replace(std::string filename, std::string removeString,
          std::string insertString);
  ~Replace();

 private:
  std::string _filename;
  std::string _removeString;
  std::string _insertString;
  void _replace(std::string line, std::ofstream &outputFile);
};

#endif